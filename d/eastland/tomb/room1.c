#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下石室");
	set_long( 
@C_LONG_DESCRIPTION
你進入了一個寬闊的石室，這兒似乎是迷宮的終點。四周的牆壁是用上好石磚砌成的，
在房間的中央有四支柱子，柱上彩繪了栩栩如生的巨龍。包圍在柱子中央的是一座看似祭壇
的東西，上面雕鑄了奇異的文字(writings)，看來年代相當久遠了。左邊牆角似乎有什麼東
西，但是你看不清楚。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/room4", 
		"south" : TOMB"/maze10",
		"east"  : TOMB"/room2",
		"west"  : TOMB"/room3"  ]) );
	set( "exit_suppress" , ({ "west", }) );
	set( "pre_exit_func", ([
		"west" : "check_WALL" ]) );		
	reset();	
}
void init()
{
	add_action( "do_look", "look");
	add_action( "do_search", "search");
}

int do_look (string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "")
	return notify_fail(" 看啥 ??\n");
	
	if ( str == "writings" ) {
		if ( (int)player->query_skill("runes") > 50 ) {
			tell_object( player, 
			"『  洞天福地  』\n" );
			return 1; }
		else 
			tell_object( player, 
				"你覺得眼花撩亂，看不清楚這些字。\n" );
				return 1;
	}
	if ( str == "west" ) 
		return 1;
	return 0;
}

int do_search(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "" )
		return notify_fail("Search what??\n");
	
	if ( str == "corner" ) {
		tell_object( player, 
			"當你仔細搜尋牆角，發現西邊有個小暗門可以進入!!\n"
			);
	        player->set_temp("WALL",1);
	return 1; }
	else return 0;
}

int check_WALL()
{
	object player;
	
	player = this_player();
	
	if ( player->query_temp("WALL") ) {
		player->delete_temp("WALL");
		return 0; }
	else return 1;
}