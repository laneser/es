#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "swamp berry", "沼澤莓果" );
        set("no_sale",1);
	add( "id", ({"berry"}) );
	set_short( "沼澤莓果" );
	set_long(
		"這是一種有著難聞臭味的黑色沼澤莓果。你可以嚐嚐(taste)看。\n"
	);
	set( "ident", "SWAMP_BERRY" );
set("unit","顆");
	set( "savour","acrimony");
	set( "effect","simple_poison");
	set( "duration",3);
	set( "damage",2);
        set( "weight", 2 );
	set( "value", ({ 10, "silver" }) );
}
