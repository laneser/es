// File: 12,6.island.c

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
		"west"  : ISLAND"11,6.island", 
		"north" : ISLAND"12,5.island", 
		"east"  : ISLAND"13,6.island",
		]) );
	set( "original", ISLAND"12,6" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 12 );
	set( "y_coordinate", 6 );
        set( "no_monster", 1 );
        set( "objects",([
                 "t1":IMON"turtle",
                 "t2":IMON"turtle1"
                 ]));
	reset();
}
