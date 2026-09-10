#include <mudlib.h>

inherit "/std/reagent";

void create()
{
	set_name( "purple ratter", "紫心藤" );
	add("id",({"ratter"}) );
	set_short("紫心藤" );
	set_long(
		"這根紫心藤表面是綠色的, 可是切面中心卻有異樣的紫色。你可以嚐嚐(taste)他的味道。\n"
	);
	set( "ident", "PURPLE_RATTER" );
	set( "unit", "根" );
        set( "weight", 2 );
	set( "savour","bitter");
	set( "effect","slow");
	set( "frequency",4);
	set( "difference",6);
	set( "value", ({ 100, "silver" }) );
}

