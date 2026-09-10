// File: 11,7.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("林蔭道");
	set_long( @LONG_DESCRIPTION
這位在森林中的道路是魔族所造的，由石板鋪成的路面，筆直的在樹
林中穿過，兩旁的樹木正好把陽光濾掉，走在這兒你覺得十分涼爽；東西
向的林蔭道，到這兒就停了，再往東有個小湖，看來不像有城堡的樣子，
看來要到津鳴城要費一番工夫了！
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"10,7.island", 
		"north" : ISLAND"11,6.island", 
		"east"  : "/d/island/forest/area/start",
		"south" : ISLAND"11,8.island",
		]) );
	set( "original", ISLAND"11,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 7 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
