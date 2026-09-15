//#pragma save_binary

// snapshotd.c
// 玩家存檔的輪替快照。
//
// autosave 只會蓋掉正式存檔，這支 daemon 負責在每次存檔完成之後另外留一份
// 可以回溯的副本。它跟隔壁的 backup.c 不一樣：backup 只保留「最後一份」，
// 這裡保留一串。
//
// 快照分兩層放在同一個目錄裡：
//   1. 近期環 —— 檔名是 <時戳>，保留最新的 SNAPSHOT_KEEP 份。
//   2. 長期三格 —— 檔名是 d1-<時戳>、d7-<時戳>、d30-<時戳>，分別是大約
//      一天前、一週前、一個月前的樣子，由 cascade() 逐格往下推。
//
// 一個玩家有兩個存檔（軀殼在 /std/user_ob/<種族>/…，連線在 /std/connection/…），
// 兩個都要留，而且共用同一個時戳，還原時才配得起來。

#include <mudlib.h>
#include <daemons.h>
#include <config.h>
#include <uid.h>

inherit DAEMON;

#define SNAPSHOT_DIR	(DATA_DIR + "/snapshots")

//  近期環保留幾份。配合 AUTOSAVE（23 分鐘）大約涵蓋最近九個小時。
#define SNAPSHOT_KEEP	24

//  兩次快照之間至少要隔這麼久，免得反覆登入登出把近期環洗光。
//  一定要小於 AUTOSAVE，否則定時存檔會被擋掉。
#define SNAPSHOT_GAP	(5 * 60)

//  單一存檔超過這個大小就不留快照。驅動的 maximum read file size 是 200000，
//  超過的話 read_file() 會讀不完整，寧可不留也不要留一份壞的。
#define SNAPSHOT_MAX	100000

#define ONE_DAY		(24 * 60 * 60)

//  長期三格的標籤，以及每一格至少要撐多久才換新的一份。
nosave string *tier_tag = ({ "d1", "d7", "d30" });
nosave int *tier_age = ({ ONE_DAY, 7 * ONE_DAY, 30 * ONE_DAY });

void create()
{
	seteuid( getuid() );
}

//  給 spec 與指令看的設定值，免得兩邊各寫一份常數。
int query_keep() { return SNAPSHOT_KEEP; }
int query_gap() { return SNAPSHOT_GAP; }
string *query_tier_tag() { return tier_tag; }
int *query_tier_age() { return tier_age; }

//  <快照根>/std/user_ob/human/a/admin
string snapshot_dir( object ob )
{
	string name;

	if( !ob ) return 0;
	name = (string)ob->query( "name" );
	if( !stringp( name ) || name == "" ) return 0;
	return SNAPSHOT_DIR + base_name( ob ) + "/" + name[0..0] + "/" + name;
}

//  把快照檔名拆成 ({ 標籤, 時戳 })。近期環的標籤是空字串。
//  不是快照檔就回傳 0。純函式，spec 直接測它。
mixed *parse_name( string file )
{
	string tag, stamp;
	int l, e;

	if( !stringp( file ) ) return 0;
	e = strlen( SAVE_EXTENSION );
	l = strlen( file );
	if( l <= e || file[l-e..l-1] != SAVE_EXTENSION ) return 0;
	file = file[0..l-e-1];
	if( sscanf( file, "%s-%s", tag, stamp ) == 2 )
		return ({ tag, to_int( stamp ) });
	return ({ "", to_int( file ) });
}

//  在一串檔名裡找某一格長期快照是哪個檔；沒有就回傳 0。
string tier_file( string *files, string tag )
{
	mixed *parsed;
	int i;

	if( !arrayp( files ) ) return 0;
	for( i = 0; i < sizeof( files ); i++ ) {
		parsed = parse_name( files[i] );
		if( parsed && parsed[0] == tag ) return files[i];
	}
	return 0;
}

//  算出長期三格這一輪要做哪些動作，回傳 ({ ({ 動作, 來源, 目的 }), … }），
//  動作是 "rm"（目的為 0）、"rename" 或 "copy"。
//
//  規則：d1 還不到一天就整串不動；到了就把舊的 d1 推去 d7（d7 還沒滿一週的
//  話舊 d1 直接丟掉），d7 推去 d30 同理，最後把 newest 複製成新的 d1。
//
//  這裡是整支 daemon 唯一難的地方，所以刻意寫成不碰檔案的純函式，
//  由 snapshotd.spec.c 直接餵檔名清單驗證。
mixed *plan_cascade( string *files, string newest, int now )
{
	string from, to, *moved;
	mixed *parsed, *ops;
	int i, stamp;

	ops = ({ });
	moved = ({ });
	if( !arrayp( files ) ) return ops;

	//  由最舊的一格往回檢查，這樣同一次呼叫裡不會把一份資料推兩格。
	//  files 是動手之前的清單，所以 d7 會在被 d1 蓋掉之前先讀到。
	for( i = sizeof( tier_tag ) - 1; i >= 0; i-- ) {
		from = ( i == 0 ) ? newest : tier_file( files, tier_tag[i-1] );
		if( !from ) continue;

		if( i > 0 ) {
			//  來源自己要先在上一格待滿才有資格往下推。少了這一關，剛開機
			//  的頭一個小時就會把幾分鐘前的東西塞進 d7 跟 d30，接下來一週
			//  到一個月都在騙人。
			parsed = parse_name( from );
			if( !parsed || now - parsed[1] < tier_age[i-1] ) continue;
		}

		to = tier_file( files, tier_tag[i] );
		//  這一格的舊住戶剛剛才被推去下一格，所以現在是空的。
		if( to && member_array( to, moved ) != -1 ) to = 0;
		if( to ) {
			parsed = parse_name( to );
			//  這一格還沒撐滿，來源就留在原地等下一輪。
			if( parsed && now - parsed[1] < tier_age[i] ) continue;
			ops += ({ ({ "rm", to, 0 }) });
		}

		parsed = parse_name( from );
		stamp = parsed ? parsed[1] : now;
		//  近期環那一份要留著，所以第一格是複製，其餘是搬移。
		ops += ({ ({ ( i == 0 ) ? "copy" : "rename", from,
			sprintf( "%s-%d%s", tier_tag[i], stamp, SAVE_EXTENSION ) }) });
		if( i > 0 ) moved += ({ from });
	}
	return ops;
}

protected void cascade( string dir, string newest, int now )
{
	mixed *ops;
	int i;

	ops = plan_cascade( get_dir( dir + "/" ), newest, now );
	for( i = 0; i < sizeof( ops ); i++ )
		switch( ops[i][0] ) {
			case "rm":
				rm( dir + "/" + ops[i][1] );
				break;
			case "rename":
				rename( dir + "/" + ops[i][1], dir + "/" + ops[i][2] );
				break;
			case "copy":
				write_file( dir + "/" + ops[i][2],
					read_file( dir + "/" + ops[i][1] ) );
				break;
		}
}

//  近期環超過 SNAPSHOT_KEEP 份時，算出該刪掉哪幾個（最舊的那些）。
//  長期三格不在這裡處理。純函式，spec 直接測它。
string *plan_trim( string *files )
{
	string *ring, swap;
	mixed *parsed;
	int i, j;

	ring = ({ });
	if( !arrayp( files ) ) return ring;
	for( i = 0; i < sizeof( files ); i++ ) {
		parsed = parse_name( files[i] );
		if( parsed && parsed[0] == "" ) ring += ({ files[i] });
	}
	if( sizeof( ring ) <= SNAPSHOT_KEEP ) return ({ });

	//  檔名是等長的 time() 值，字串由小排到大就是由舊排到新。
	for( i = 1; i < sizeof( ring ); i++ )
		for( j = i; j > 0 && ring[j] < ring[j-1]; j-- ) {
			swap = ring[j];
			ring[j] = ring[j-1];
			ring[j-1] = swap;
		}
	return ring[0..sizeof( ring ) - SNAPSHOT_KEEP - 1];
}

protected void trim( string dir )
{
	string *doomed;
	int i;

	doomed = plan_trim( get_dir( dir + "/" ) );
	for( i = 0; i < sizeof( doomed ); i++ )
		rm( dir + "/" + doomed[i] );
}

//  替單一個存檔物件留一份快照。回傳有沒有寫成功。
protected int snap_one( object ob, int now )
{
	string dir, src, dest, data;
	int size;

	dir = snapshot_dir( ob );
	if( !dir ) return 0;

	src = user_data_file( ob ) + SAVE_EXTENSION;
	size = file_size( src );
	//  還沒存過檔（-1）或空檔就沒什麼好留的。
	if( size <= 0 ) return 0;
	if( size > SNAPSHOT_MAX ) {
		log_file( "SNAPSHOT", sprintf( "%s: %s 太大（%d bytes），略過。\n",
			ctime( now ), src, size ) );
		return 0;
	}

	data = read_file( src );
	if( !stringp( data ) || data == "" ) return 0;

	if( file_size( dir ) != -2 ) mkdirs( dir );
	dest = dir + "/" + sprintf( "%d%s", now, SAVE_EXTENSION );
	if( file_exists( dest ) ) rm( dest );
	if( !write_file( dest, data ) ) {
		log_file( "SNAPSHOT", sprintf( "%s: 寫不進 %s。\n", ctime( now ), dest ) );
		return 0;
	}

	cascade( dir, sprintf( "%d%s", now, SAVE_EXTENSION ), now );
	trim( dir );
	return 1;
}

//  近期環裡最新一份的時戳；沒有就回傳 0。
protected int last_stamp( string dir )
{
	string *files;
	mixed *parsed;
	int i, newest;

	files = get_dir( dir + "/" );
	if( !arrayp( files ) ) return 0;
	for( i = 0; i < sizeof( files ); i++ ) {
		parsed = parse_name( files[i] );
		if( parsed && parsed[0] == "" && parsed[1] > newest ) newest = parsed[1];
	}
	return newest;
}

//  由玩家軀殼自己（或任何 root 權限的物件）呼叫，替軀殼與連線各留一份。
//  force 不為 0 時略過 SNAPSHOT_GAP 的節流。回傳實際寫出幾個檔。
varargs int take_snapshot( object body, int force )
{
	object link, prev;
	string dir;
	int now, n;

	prev = previous_object();
	if( prev != body && geteuid( prev ) != ROOT_UID ) return 0;
	if( !body || !userp( body ) ) return 0;

	seteuid( getuid() );

	dir = snapshot_dir( body );
	if( !dir ) return 0;

	now = time();
	if( !force ) {
		int last;

		last = last_stamp( dir );
		if( last && now - last < SNAPSHOT_GAP ) return 0;
	}

	n = snap_one( body, now );
	link = (object)body->query_link();
	if( link ) n += snap_one( link, now );
	return n;
}

//  找出某個玩家的軀殼快照目錄。玩家不在線上時不知道種族，只能掃過去找。
string find_body_dir( string name )
{
	string *races, base, dir;
	int i;

	if( !stringp( name ) || name == "" ) return 0;
	base = SNAPSHOT_DIR + "/std/user_ob/";
	races = get_dir( base );
	if( !arrayp( races ) ) return 0;
	for( i = 0; i < sizeof( races ); i++ ) {
		dir = base + races[i] + "/" + name[0..0] + "/" + name;
		if( file_size( dir ) == -2 ) return dir;
	}
	return 0;
}

string find_link_dir( string name )
{
	string dir;

	if( !stringp( name ) || name == "" ) return 0;
	dir = SNAPSHOT_DIR + "/std/connection/" + name[0..0] + "/" + name;
	return ( file_size( dir ) == -2 ) ? dir : 0;
}

//  列出某個玩家的快照，由新到舊，每一筆是 ({ 標籤, 時戳, 大小 })。
//  標籤是空字串代表近期環，其餘是 d1 / d7 / d30。
mixed *query_snapshots( string name )
{
	string dir, *files;
	mixed *parsed, *out, *swap;
	int i, j;

	dir = find_body_dir( name );
	if( !dir ) return ({ });
	files = get_dir( dir + "/" );
	if( !arrayp( files ) ) return ({ });

	out = ({ });
	for( i = 0; i < sizeof( files ); i++ ) {
		parsed = parse_name( files[i] );
		if( !parsed ) continue;
		out += ({ ({ parsed[0], parsed[1],
			file_size( dir + "/" + files[i] ) }) });
	}

	//  份數頂多二十幾，插入排序就夠了。
	for( i = 1; i < sizeof( out ); i++ )
		for( j = i; j > 0 && out[j][1] > out[j-1][1]; j-- ) {
			swap = out[j];
			out[j] = out[j-1];
			out[j-1] = swap;
		}
	return out;
}

//  由快照目錄推回正式存檔的路徑：
//    /data/snapshots/std/user_ob/human/a/admin  ->  /data/std/user_ob/human/a/admin.o
protected string live_file( string dir, string name )
{
	string rel;
	int head, tail;

	head = strlen( SNAPSHOT_DIR );
	//  砍掉尾巴的 "/<name>"，剩下的就是玩家存檔所在的目錄。
	tail = strlen( dir ) - strlen( name ) - 2;
	if( tail < head ) return 0;
	rel = dir[head..tail];
	return DATA_DIR + rel + "/" + name + SAVE_EXTENSION;
}

//  把指定的快照寫回正式存檔，軀殼與連線一起。
//  tag 是 query_snapshots() 給的標籤（近期環是空字串），stamp 是時戳。
//  只有 root 權限的物件叫得動，而且玩家必須不在線上 —— 線上的話記憶體裡那份
//  會在下次存檔時把還原的結果蓋掉。
int restore_snapshot( string name, string tag, int stamp )
{
	string file, data, live, live_dir, *dirs;
	int done, i;

	if( geteuid( previous_object() ) != ROOT_UID ) return 0;
	if( !stringp( name ) || name == "" ) return 0;
	if( find_player( name ) ) return 0;

	seteuid( getuid() );

	file = ( stringp( tag ) && tag != "" )
		? sprintf( "%s-%d%s", tag, stamp, SAVE_EXTENSION )
		: sprintf( "%d%s", stamp, SAVE_EXTENSION );

	dirs = ({ find_body_dir( name ), find_link_dir( name ) });
	for( i = 0; i < sizeof( dirs ); i++ ) {
		if( !dirs[i] || !file_exists( dirs[i] + "/" + file ) ) continue;
		data = read_file( dirs[i] + "/" + file );
		if( !stringp( data ) || data == "" ) continue;
		live = live_file( dirs[i], name );
		if( !live ) continue;
		//  正式存檔的目錄不一定還在（玩家被 purge 過、或整個 data/ 是新的），
		//  不先補出來 write_file() 會直接拋錯。
		live_dir = live[0..strlen( live ) - strlen( name ) -
			strlen( SAVE_EXTENSION ) - 2];
		if( file_size( live_dir ) != -2 ) mkdirs( live_dir );
		if( file_exists( live ) ) rm( live );
		if( write_file( live, data ) ) done++;
	}

	if( done )
		log_file( "SNAPSHOT", sprintf( "%s: %s 還原 %s 的 %s（%d 個檔）。\n",
			ctime( time() ), this_player() ?
			(string)this_player()->query( "name" ) : "?", name, file, done ) );
	return done;
}
