#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "yellow mushroom", "黃蘑菇" );
        set("no_sale",1);
	add( "id", ({"mushroom"}) );
	set_short( "a yellow mushroom", "黃蘑菇" );
	set_long(
		"You see a yellow mushroom with small white mushroom.\n",
		"這是一種有著黃色蕈頂和白色小斑點的蘑菇。你可以嚐嚐(taste)他的味道。\n"
	);
        set( "unit", "顆");
	set( "ident", "YELLOW_MUSHROOM" );
	set( "savour","acidity");
	set( "effect","simple_poison");
	set( "duration",5);
	set( "damage",3);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
