#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("poet's cloth","詩人之服");
        add("id",({"cloth"}) );
         set_short( "poet's cloth","詩人之服");
	set_long(
"This is a poet's cloth . \n"
"這是一件詩人專用的衣服\n"
	);
	set( "unit", "件" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 10 );
	set( "defense_bonus", 2 );
	set( "special_defense", ([ "mental":2, "fire":-2, "acid":-2 ]) );
	set( "value", ({ 420, "silver" }) );
}
