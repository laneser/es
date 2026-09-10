#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("holy ring","愛染明王戒指");
    add("id",({"ring"}) );
    set_short( "a holy ring","愛染明王戒指");
	set_long(
		"This is a ring blessed by God.\n"
		"這是五大明王之一 — 愛染明王使用過的戒指,如果你是善良\n"
		"正義之士, 它將以明王之名加護你的。\n" 
	);
	set( "unit", "個" );
	set( "weight", 12 );
	set( "type", "finger" );
    set( "material","monk");
	set( "armor_class", 0 );
	set( "defense_bonus", 9 );
	set( "value", ({ 300, "gold" }) );
	set( "no_sale", 1 );
}
