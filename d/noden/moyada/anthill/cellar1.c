// translation done -Elon 03-10-94 (dumb...)
#include "../moyada.h"
#include "anthill.c"

inherit ROOM;

void create()
{
	::create();
	set_short("蟻穴");
	set_long( @C_LONG_DESCRIPTION
你在洞穴的中間，北邊和南邊都有平伸的洞穴，幾隻工蟻正在你身旁爬上爬下
似乎在確認你是否是它們的同類，你還可以繼續爬(climb down)下去看看。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
		"north" : MOYADA"anthill/greeting_hall",
		"south" : MOYADA"anthill/rest_room",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant solider"  : MOYADA"monster/ant_solider",
	   "ant killer"   : MOYADA"monster/ant_killer",
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
      to_climb_down( this_player(), MOYADA"anthill/cellar2", 
        MOYADA"anthill/dump", 35, 15 );
    else if( str == "up" )
      to_climb_up( this_player(), MOYADA"anthill/entrance", 35 );
    return 1;
}
