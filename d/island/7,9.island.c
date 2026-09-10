// File: 7,9.island.c

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
，你想你對於蜥蜴人的智商要重新評估了；這不甚美觀但是很實用的道路
是南北向的，它通往蜥蜴人的居所，走在上面要小心別把衣服弄髒了。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"6,9.island", 
		"north" : ISLAND"7,8.island", 
		"east"  : ISLAND"8,9.island",
		"south" : ISLAND"7,10.island",
		]) );
	set( "original", ISLAND"7,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 9 );
	reset();
#include <replace_room.h>
}
