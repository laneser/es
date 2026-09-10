#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "black lotus", "黑沼蓮心" );
	add( "id", ({"lotus"}) );
	set_short( "黑沼蓮心" );
	set_long(
		"黑沼蓮心是由一種生長在沼澤中的蓮子心曬乾製成的。色呈淡粉紅,\n"
		"有些淡淡的香。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "unit","包");
	set( "ident", "BLACK_LOTUS" );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",3);
        set( "weight", 1 );
	set( "value", ({ 15, "silver" }) );
}

