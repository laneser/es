// translation done -Elon 03-10-94
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("蟻穴");
	set_long( @C_LONG_DESCRIPTION
你在洞穴的中間，東南邊有一個平伸的洞穴，幾隻兵蟻正在你身旁爬上爬下
似乎在確認你是否是它們的同類，你還可以繼續爬(climb down)下去看看。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
	    "westdown"  : MOYADA"anthill/cabaret",
		"southeast" : MOYADA"anthill/kitchen",
	]) );
	set( "objects", ([
	   "ant worker"    : MOYADA"monster/ant_worker",
	   "ant fighter#1" : MOYADA"monster/ant_fighter",
	   "ant fighter#2" : MOYADA"monster/ant_fighter",
	   "ant knight"    : MOYADA"monster/ant_knight",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",4);
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
      to_climb_down( this_player(), MOYADA"anthill/cellar3", 
        MOYADA"anthill/dump", 35, 10 );
    else if( str == "up" )
      to_climb_up( this_player(), MOYADA"anthill/cellar1", 35 );
    return 1;
}
