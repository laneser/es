// File: 9,10.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("沼澤");
	set_long( @LONG_DESCRIPTION
在這沼澤中長了不少植物，尤其是原本該是泥水的地面，也被一些草
本植物蓋滿了，你走在這兒應該注意地面，否則會陷入泥沼，無法自拔。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"8,10.island", 
		"north" : ISLAND"9,9.island", 
		"east"  : ISLAND"10,10.island",
		"south" : ISLAND"9,11.island",
		]) );
	set( "original", ISLAND"9,10" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 10 );
	reset();
#include <replace_room.h>
}

