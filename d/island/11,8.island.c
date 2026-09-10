// File: 11,8.island.c

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
		"west"  : ISLAND"10,8.island", 
		"north" : ISLAND"11,7.island", 
		"east"  : ISLAND"12,8.island",
		"south" : ISLAND"11,9.island",
		]) );
	set( "original", ISLAND"11,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 11 );
	set( "y_coordinate", 8 );
	reset();
#include <replace_room.h>
}

