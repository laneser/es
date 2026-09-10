// File: 5,11.island.c

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
		"west"  : ISLAND"4,11.island", 
		"north" : ISLAND"5,10.island", 
		"east"  : ISLAND"6,11.island",
		"south" : ISLAND"5,12.island",
		]) );
	set( "original", ISLAND"5,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 11 );
	reset();
#include <replace_room.h>
}
