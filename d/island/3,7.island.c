// File: 3,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("車馬道");
	set_long( @LONG_DESCRIPTION
這是蜿蜒在丘陵之中的道路，其實也不是刻意鋪出來的，而是來往人
馬將地面上踏出一條小路，路是人走出來的，這話還真是沒錯；這小路是
東西向的，到這就到目的地了，在你西邊的是宏偉的武士堡！快進去吧！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : "/d/island/samurai/room/station", 
		"north" : ISLAND"3,6.island", 
		"east"  : ISLAND"4,7.island",
		"south" : ISLAND"3,8.island",
		]) );
	set( "original", ISLAND"3,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 3 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

