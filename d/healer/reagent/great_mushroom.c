#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "great mushroom", "靈芝" );
	add("id",({"mushroom"}) );
	set_short("靈芝" );
	set_long(
		"這塊靈芝是用來做藥引的, 不能直接生吃, 不過你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "GREAT_MUSHROOM" );
	set( "unit", "塊" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "value", ({ 120, "silver" }) );
}
