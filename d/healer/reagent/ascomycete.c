#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "ascomycete", "付子菌" );
	add( "id", ({"reagent"}) );
	set_short("付子菌" );
	set_long(
		"這堆付子菌表面成黑色, 還閃爍著一些鱗光。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "ASCOMYCETE" );
	set( "unit", "堆" );
        set( "weight", 1 );
	set( "effect","slow");
	set( "frequency",5);
	set( "difference",4);
	set( "value", ({ 50, "silver" }) );
}
