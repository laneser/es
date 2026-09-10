// File: 6,4.island.c

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
		"west"  : ISLAND"5,4.island", 
		"north" : ISLAND"6,3.island", 
		"east"  : ISLAND"7,4.island",
		"south" : ISLAND"6,5.island",
		]) );
	set( "original", ISLAND"6,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 4 );
        set( "no_monster" , 1 );
	reset();
#include <replace_room.h>
}
