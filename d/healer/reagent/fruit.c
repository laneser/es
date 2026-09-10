#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "fruit", "果實" );
	add("id",({"fruit"}) );
	set_short("果實" );
	set_long(
		"這顆果實看起來很像蘋果, 但是表面佈滿細細的絨毛。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "NO_NAME_FRUIT" );
	set( "unit", "顆" );
        set( "weight", 2 );
	set( "savour","sweet");
	set( "effect","simple_poison");
	set( "duration",4);
	set( "damange",6);
	set( "no_sale",1);
}

