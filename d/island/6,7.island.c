// File: 6,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("西村口");
	set_long( @LONG_DESCRIPTION
往東就是謫仙島正中央的映世村了，映世村是位在一個略成圓形的小
丘上，丘的東北、東南、西北、西南四個方向各有一個水流出口，水源似
乎來自地底，當然它們就是島上四條小溪的源頭，如果你要進村的話可以
沿石階而上，而從這往西是起伏不定的小丘陵，那是屬於武士堡的勢力領
域。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,7.island", 
		"eastup"  : ITOWN"town03",
		]) );
	set( "original", ISLAND"6,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
