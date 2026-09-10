// File: 9,7.island.c

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
向的林蔭道，連接了映世村和津鳴城。
LONG_DESCRIPTION
	);



	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,7.island", 
		"north" : ISLAND"9,6.island", 
		"east"  : ISLAND"10,7.island",
		"south" : ISLAND"9,8.island",
		]) );
	set( "original", ISLAND"9,7" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 7 );
	reset();
#include <replace_room.h>
}
