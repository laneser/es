//#pragma save_binary

// _snapshot.c
// 列出與還原玩家存檔的輪替快照，資料由 /adm/daemons/snapshotd.c 產生。
//
// 列出是巫師權限，還原是 admin 權限 —— 還原會直接蓋掉正式存檔，
// 跟 /cmds/adm/_restore.c 同一個等級的操作。

#include <mudlib.h>
#include <daemons.h>
#include <uid.h>

inherit DAEMON;

int help();

//  標籤對應的說明，列表時放在後面。
protected string tag_note( string tag )
{
	switch( tag ) {
		case "d1"  : return "（約一天前）";
		case "d7"  : return "（約一週前）";
		case "d30" : return "（約一個月前）";
		default    : return "";
	}
}

protected int list_snapshots( string user )
{
	mixed *snaps;
	string tag;
	int i;

	snaps = (mixed *)SNAPSHOT_D->query_snapshots( user );
	if( !sizeof( snaps ) )
		return notify_fail( user + " 沒有任何快照。\n" );

	write( set_color( user + " 的存檔快照（由新到舊）：\n", "HIC" ) );
	for( i = 0; i < sizeof( snaps ); i++ ) {
		tag = snaps[i][0];
		write( sprintf( "  %-6s %-10d %s  %5d bytes %s\n",
			( tag == "" ) ? "-" : tag, snaps[i][1],
			extract( ctime( snaps[i][1] ), 4, 15 ),
			snaps[i][2], tag_note( tag ) ) );
	}
	write( "\n還原請用： snapshot " + user + " <時戳>"
		"　（長期那三份要打 snapshot " + user + " d1 這種形式）\n" );
	return 1;
}

int cmd_snapshot( string str )
{
	string user, which, tag;
	int stamp, n;

	seteuid( getuid() );

	if( !str || str == "" ) return help();

	if( sscanf( str, "%s %s", user, which ) != 2 ) {
		user = str;
		which = 0;
	}
	user = lower_case( user );

	if( !which ) return list_snapshots( user );

	//  以下是還原，門檻拉到 admin。
	if( !member_group( getuid( this_player() ), "admin" ) )
		return notify_fail( "只有 admin 可以還原別人的存檔。\n" );

	if( find_player( user ) )
		return notify_fail( user + " 現在在線上，"
			"要請他先 quit —— 不然記憶體裡那份會把還原的結果蓋回去。\n" );

	//  d1 / d7 / d30 這種長期標籤要翻成 ({ 標籤, 時戳 })，直接打時戳的就照用。
	if( sscanf( which, "%d", stamp ) == 1 && which == "" + stamp )
		tag = "";
	else {
		mixed *snaps;
		int i;

		tag = which;
		stamp = 0;
		snaps = (mixed *)SNAPSHOT_D->query_snapshots( user );
		for( i = 0; i < sizeof( snaps ); i++ )
			if( snaps[i][0] == tag ) {
				stamp = snaps[i][1];
				break;
			}
		if( !stamp )
			return notify_fail( user + " 沒有 " + tag + " 這份快照。\n" );
	}

	n = (int)SNAPSHOT_D->restore_snapshot( user, tag, stamp );
	if( !n )
		return notify_fail( "還原失敗，找不到對應的快照檔。\n" );

	write( sprintf( "已經把 %s 的存檔還原成 %s（%d 個檔）。\n",
		user, extract( ctime( stamp ), 4, 15 ), n ) );
	if( n < 2 )
		write( set_color( "注意：只還原了一個檔，"
			"軀殼與連線的資料可能對不起來。\n", "HIY" ) );
	return 1;
}

int help()
{
	write( @C_HELP
H指令格式: snapshot <玩家>
          snapshot <玩家> <時戳>
          snapshot <玩家> d1 | d7 | d30

列出或還原某個玩家的存檔快照。

存檔本身只會被蓋掉，快照是另外留的副本，由 /adm/daemons/snapshotd.c 在每次
存檔完成後自動產生，分成兩種：

  近期環     最新的 24 份，大約涵蓋最近九個小時。列表裡標籤顯示為 -。
  d1/d7/d30  額外保留的三份，分別是大約一天前、一週前、一個月前的樣子。

不帶時戳就是列出清單，巫師即可。帶時戳（或 d1 這種標籤）是還原，只有 admin
可以下，而且該玩家必須不在線上 —— 線上的話記憶體裡那份會在下次存檔時把還原
的結果蓋回去。

還原會同時處理軀殼與連線兩個存檔。相關指令見 backup、restore。

C_HELP
	);
	return 1;
}
