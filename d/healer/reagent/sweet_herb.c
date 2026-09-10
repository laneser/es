#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "sweet herb", "甘草" );
       set("no_sale",1);
	add("id",({"herb"}));
	set_short( "甘草" );
	set_long(
		"甘草藥性溫和, 在某些藥方中是不可缺的藥引。你可以嚐嚐(taste)看。\n"
	);
	set( "ident", "SWEET_HERB" );
	set( "unit", "根" );
        set( "weight", 2);
	set( "savour","sweet");
         set( "value",({50, "silver" }) );
}
