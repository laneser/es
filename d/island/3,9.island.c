// File: 3,9.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("海灘");
	set_long( @LONG_DESCRIPTION
這海灘的沙子是黃金色的，除此之外，夾雜在沙中的石英質，不斷的
反著光線，一閃閃的，與蔚藍海面上的粼煦波光，相映成趣。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"2,9.island", 
		"north" : ISLAND"3,8.island", 
		"east"  : ISLAND"4,9.island",
		"south" : ISLAND"3,10.island",
		]) );
	set( "original", ISLAND"3,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 3 );
	set( "y_coordinate", 9 );
        set( "no_monster", 1 );
	reset();
}
