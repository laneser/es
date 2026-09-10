// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("蟻穴");
	set_long( @C_LONG_DESCRIPTION
你在洞穴的中間，東南邊和西邊各有一個平伸的洞穴，幾隻騎士蟻正在你身旁爬上
爬下似乎在確認你是否是它們的同類，你還可以繼續爬(climb down)下去看看。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"southeast" : MOYADA"anthill/check_point",
        "westup"    : MOYADA"anthill/cabaret",
	]) );
	set( "objects", ([
	   "ant knight#1" : MOYADA"monster/ant_knight",
	   "ant knight#2" : MOYADA"monster/ant_knight",
	   "ant solider"  : MOYADA"monster/ant_solider",
	   "ant killer#1" : MOYADA"monster/ant_killer",
	   "ant killer#2" : MOYADA"monster/ant_killer",
	   "ant killer#3" : MOYADA"monster/ant_killer",
	]) );
	reset();
}

void init()
{
    add_action("to_climb", "climb");
}

int to_climb( string str )
{
    if( !str || str=="" )
      return notify_fail("你要爬哪個方向?\n");
    if( str != "down" && str != "up" )
      return notify_fail("那個方向不通啦!\n");
    if( str == "down" )
      to_climb_down( this_player(), MOYADA"anthill/dump", 
        MOYADA"anthill/dump", 35, 5 );
    else if( str == "up" )
      to_climb_up( this_player(), MOYADA"anthill/cellar2", 35 );
    return 1;
}
