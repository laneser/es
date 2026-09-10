#include <mudlib.h>
inherit "/std/reagent.c";


void create()
{
	set_name( "snake bursa", "毒蛇毒囊" );
        set("no_sale",1);
	add( "id", ({"bursa"}) );
	set_short( "毒蛇毒囊" );
	set_long(
		"這是一顆毒蛇的毒囊, 有人喜歡拿它來泡酒,聽說還蠻補的。\n"
		"如果你不怕死的話,可以嚐嚐(taste)它。\n"
	);
	set( "unit", "顆" );
	set( "ident", "SNAKE_BURSA" );
        set( "weight", 2 );
	set( "value", ({ 40, "silver" }) );
        set ( "effect","simple_poison");
        set ( "duration",2);
        set ( "damage",2);
        set ( "savour","sweet");
}

