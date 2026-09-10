// File: 9,11.island.c

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
		"west"  : ISLAND"8,11.island", 
		"north" : ISLAND"9,10.island", 
		"east"  : ISLAND"10,11.island",
		"south" : ISLAND"9,12.island",
		]) );
	set( "original", ISLAND"9,11" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 9 );
	set( "y_coordinate", 11 );
	reset();
#include <replace_room.h>
}
