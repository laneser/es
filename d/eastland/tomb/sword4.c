#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("劍冢");
	set_long( 
@C_LONG_DESCRIPTION
			『  劍冢  』
             你被迎面而來的這兩個龍飛鳳舞的大字震撼住 !! 
好不容易回過神來，卻又被四周的景象嚇了一跳，竟有如此多的劍放置於此，難怪剛才會有
那種感覺，原來是這些劍一起發出的殺意、劍氣構成了那麼蝕骨的寒意。它們不知道已經被
放在這裡多久了，然而每把劍依舊精光閃閃，彷佛在不甘寂寞地述說著它們輝煌的過去。在
庭中有一個六角型的石墩(stone)，不知道有何用途。
C_LONG_DESCRIPTION
	);

	set( "light", 1);
	set( "OUT", 0);
	set( "exits", ([ 
		"north": TOMB"/sword6",
		"south": TOMB"/sword5",
		"east" : TOMB"/sword3",
		"west" : TOMB"/sword7"  ]) );
	create_door( "east","west",
		   (["keyword" : ({"door", "iron"}),
		     "name"    : "iron door",
		     "c_name"  : "大鐵門",
		     "desc"    : "A huge iron door\n",
		     "c_desc"  : "一扇堅固的大鐵門。\n",		
		     "lock"    : "TOMBKEY_2",
		     "status"  : "locked",
		     ]) );
	add( "c_item_desc", ([
		"stone" :@STONE_DESC
在這個石墩的六個邊各有一個小孔，恰好可以容納一把劍。仔細聽則可以聽到石墩內
隱約傳來某種聲音。
STONE_DESC
	]) );	
	reset();	
}

void init()
{
	add_action("insert_sword","insert");
	add_action("unlock_door","unlock");
}

int insert_sword(string str)
{
	object player,obj;
	int seal;
	string sword,pos;
	
	player = this_player();
	seal = (int)player->query_temp("SEAL");
	if ( !str || str=="")
	return notify_fail("Syntax: insert <sword> into <position>.\n"
			   "Just type its name, no need the word 'sword'\n");
	if ( present( "sky guilt" , this_object() )  || (int)this_object()->query("OUT") == 1 ) return 1;
	if ( sscanf(str, "%s into %s", sword, pos) ) {
		if ( seal == 0 && sword == "gemmy" && pos == "center_right") {
			if ( !obj=present( "gemmy sword" , player ) )
				return notify_fail( "你沒有這把劍。\n" );
			tell_room( this_object(),
				"\n"+"石墩震動了一下。\n" );
			player->set_temp("SEAL", 1);
			obj->remove();
			return 1; }
		else if ( seal == 1 && sword == "famous" && pos == "down_left" ) {
			if ( !obj=present( "famous sword" , player) )
				return notify_fail( "你沒有這把劍。\n" );
			tell_room( this_object(), 
				"\n"+"一陣光芒自封印中發出........\n"
				"你聽到一個溫和的聲音說道：為了預防那邪獸逃脫，如果你放入第三把劍，門將會\n"
				"自動鎖上!!\n" );
			player->set_temp("SEAL", 2);
			obj->remove();
			return 1; }
		else if ( seal == 2 && sword == "antique" && pos == "up_left") {
			if ( !obj=present( "antique sword" , player) )
				return notify_fail( "你沒有這把劍。\n" );
			tell_room( this_object(), 
				"\n"+"突然一陣黑氣自石墩中衝出，同時你聽到門自動閉合並鎖上的聲音。\n" );
			obj->remove();
			new(MOB"/sky_guilt")->move(this_object());
                        this_player()->set_explore("eastland#35");
			set_status("east","locked");
			update_link("east");
			player->delete_temp("SEAL");
			this_object()->set("OUT",1);
			return 1; }
		else return notify_fail( "你要幹嘛??\n" ); 
	}
}		

int unlock_door()
{
	object player,ob;
	int chinese_mode;
	
	player = this_player();
	chinese_mode = can_read_chinese(player);
	
	if( present("cockroach", this_object()) ) {
		tell_room( this_object(), chinese_mode?
			"妖獸尚存，無法開鎖 !!\n":
			"The monster is still alive, so can't unlock the door.\n" );
		return 1; }
	return 0;
}

