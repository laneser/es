// File: 7,11.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("蘆葦便道");
	set_long( @LONG_DESCRIPTION
在沼澤中造路是很不容易的，蜥蜴人想出了好方法，將石頭以草繩綁
住，然後填在沼澤中，並在兩旁種植蘆葦，以保護路基，看了這條路以後
，你想你對於蜥蜴人的智商要重新評估了；這道路到這兒往南通往一個巖
石平臺，那兒好像是蜥蜴人洞穴的入口，你想你應該小心點唷，蜥蜴人並
不好惹啊！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,11.island", 
		"north" : ISLAND"7,10.island", 
		"east"  : ISLAND"8,11.island",
		"south" : ISLAND"7,12.island",
		]) );
	set( "original", ISLAND"7,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 11 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

