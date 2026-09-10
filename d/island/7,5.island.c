// File: 7,5.island.c

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
小徑雖然不是很直，但是大致上還是由南向北延伸的。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
	        "west"  : ISLAND"6,5.island",
		"north" : ISLAND"7,4.island",
		"east"  : ISLAND"8,5.island", 
		"south" : ISLAND"7,6.island",
		]) );
	set( "original", ISLAND"7,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 5 );
	reset();
#include <replace_room.h>
}
