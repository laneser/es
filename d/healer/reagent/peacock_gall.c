#include <mudlib.h>
inherit "/std/reagent.c";


void create()
{
	set_name( "peacock's gall", "孔雀膽" );
	add( "id", ({"gall"}) );
	set_short( "孔雀膽" );
	set_long(
		"這是一顆綠色的孔雀膽,具有強烈的毒性。\n"
		"如果你不怕死的話,可以嚐嚐(taste)它。\n"
	);
           set("no_sale",1);
	set( "unit", "顆" );
	set( "ident", "PEACOCK_GALL" );
        set( "weight", 2 );
	set( "value", ({ 20, "silver" }) );
        set ( "effect","simple_poison");
        set ( "duration",2);
        set ( "damage",40);
}

