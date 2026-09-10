#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "swamp moss", "沼澤苔" );
        set("no_sale",1);
	add( "id", ({"moss"}) );
	set_short( "some swamp moss", "沼澤苔" );
	set_long(
		"You see some green moss with dark spots.\n",
		"這是一種生長在沼澤地區的苔類，上面有一些黑色斑點。你可以嚐嚐(taste)看。\n"
	);
	set( "unit", "團" );
	set( "ident", "SWAMP_MOSS" );
	set( "effect","slow");
	set( "frequency",3);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 20, "silver" }) );
}
