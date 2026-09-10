// File: 8,11.island.c

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
		"west"  : ISLAND"7,11.island", 
		"north" : ISLAND"8,10.island", 
		"east"  : ISLAND"9,11.island",
		"south" : ISLAND"8,12.island",
		]) );
	set( "original", ISLAND"8,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 11 );
        set( "no_monster" , 1 );
        set( "objects" , ([
                    "lizard":IMON"lizardman"
                    ]));
	reset();
#include <replace_room.h>
}

