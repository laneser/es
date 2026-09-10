// File: 5,8.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("小丘陵");
	set_long( @LONG_DESCRIPTION
這起伏不大的丘陵上長滿了嫩綠的鮮草，而點綴其上的小白花，使這
裡令人覺得精神愉快，站在這兒可以看到遠方的大海，這是因為這裡都沒
有高大的植物。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,8.island", 
		"north" : ISLAND"5,7.island", 
		"east"  : ISLAND"6,8.island",
		"south" : ISLAND"5,9.island",
		]) );
	set( "original", ISLAND"5,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 8 );
	reset();
#include <replace_room.h>
}
