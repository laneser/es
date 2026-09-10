// File: 7,3.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("桃林小徑");
	set_long( @LONG_DESCRIPTION
這是蜿蜒在桃花林中的泥土小徑，路上佈滿了落下來的桃花，清新的
空氣加上悅耳的鳥鳴，還有兩旁的桃花林，使走在這兒成了最佳享受；這
小徑一路由村口往北到這就消失了，由這往北還是桃花林，不同的是好像
密了些，有些古怪，過去瞧瞧吧！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,3.island", 
		"north" : ISLAND"7,2.island", 
		"east"  : ISLAND"8,3.island",
		"south" : ISLAND"7,4.island",
		]) );
	set( "original", ISLAND"7,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 3 );
	reset();
#include <replace_room.h>
}
