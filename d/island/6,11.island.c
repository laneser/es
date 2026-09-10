// File: 6,11.island.c

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
		"west"  : ISLAND"5,11.island", 
		"north" : ISLAND"6,10.island", 
		"east"  : ISLAND"7,11.island",
		"south" : ISLAND"6,12.island",
		]) );
	set( "original", ISLAND"6,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 11 );
	reset();
#include <replace_room.h>
}
