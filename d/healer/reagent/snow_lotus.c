#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "snow lotus", "雪蓮" );
        set("no_sale",1);
	add( "id", ({"lotus"}) );
	set_short( "雪蓮" );
	set_long(
		"哇!這是由雪蓮花朵曬乾製成的藥材, 可說百年難得一見!!你可以嚐嚐(taste)他的味道。\n"
	);
	set( "unit","朵");
	set( "ident", "SNOW_LOTUS" );
	set( "savour","sweet");
	set( "effect","weak");
	set( "frequency",2);
	set( "difference",2);
        set( "weight", 2 );
	set( "value", ({ 1000, "silver" }) );
}
