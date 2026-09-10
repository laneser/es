#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "peony", "芍藥" );
set("no_sale",1);
	set_short( "芍藥" );
	set_long(
		"這是由芍藥的葉子曬乾製成的藥材。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "PEONY" );
	set( "unit", "包" );
        set( "weight", 2 );
	set( "savour","acidity");
	set( "effect","weak");
	set( "frequency",1);
	set( "difference",3);
	set( "value", ({ 40, "silver" }) );
}
