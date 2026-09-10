#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "dang guei", "當歸" );
           set("no_sale",1);
	add("id", ({"dang","guei"}) );
	set_short( "當歸" );
	set_long(
		"這是一塊用來做藥材的當歸。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "DANG_GUEI" );
	set( "unit", "塊" );
        set( "weight", 2);
	set( "savour","bitter");
	set( "value", ({ 100, "silver" }) );
}
