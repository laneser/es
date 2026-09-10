// File: 8,3.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("桃花林");
	set_long( @LONG_DESCRIPTION
你身處在一片美麗的桃花林中，這裡正是所謂的『落英繽紛，芳草鮮
美』，要是仔細觀察此處的桃樹，你會發現它們以某種巧妙的次序排列著
，但你又看不出有人力斧鑿的痕跡，或許是渾然天成的吧；在這裡站的越
久，你越覺得世間的名利鬥爭已經離你遠去，這種心曠神怡的感覺，使你
對這兒流連忘返。	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"7,3.island", 
		"north" : ISLAND"8,2.island", 
		"east"  : ISLAND"9,3.island",
		"south" : ISLAND"8,4.island",
		]) );
	set( "original", ISLAND"8,3" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 3 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
