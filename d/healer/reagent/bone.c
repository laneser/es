#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "tiger's bone", "虎骨" );
         set("no_sale",1);
	add( "id", ({ "bone" }) );
	set_short( "虎骨" );
	set_long(
                "這是老虎的頭骨, 可以做為一種藥材。你可以嚐嚐(taste)看。\n"
	);
    set( "ident","BONE");
	set( "unit", "塊" );
        set( "weight",3 );
	set( "savour","acidity");
	set( "value", ({ 300, "silver" }) );
}
