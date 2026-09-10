#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "ginseng", "人參" );
	set_short( "a ginseng", "人參" );
	set_long(
		"You see a ginseng which are used as reagents the most.\n",
		"這是一根用來做藥材的人參。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "GINSENG" );
         set("no_sale",1);
	set( "unit", "根" );
        set( "weight", 2 );
	set( "savour","bitter");

	set( "value", ({ 100, "silver" }) );
}
