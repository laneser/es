#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "yellow lotus", "黃蓮" );
         set("no_sale",1);
	add( "id", ({"lotus"}) );
	set_short( "黃蓮" );
	set_long(
		"這是一些由蓮子心曬乾製成的藥材。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "unit","包");
	set( "ident", "YELLOW_LOTUS" );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",2);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
