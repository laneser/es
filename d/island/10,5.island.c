// File: 10,5.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("樹海");
	set_long( @LONG_DESCRIPTION
這是一片由高聳入雲的巨木所構成的樹海，由於樹木很密，致使你幾
乎看不到樹林深處有什麼存在，也因此這裡從以前就有很多神秘的傳說。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"9,5.island", 
		"north" : ISLAND"10,4.island", 
		"east"  : ISLAND"11,5.island",
		"south" : ISLAND"10,6.island",
		]) );
	set( "original", ISLAND"10,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 10 );
	set( "y_coordinate", 5 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}

