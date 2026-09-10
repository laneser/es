#include "../island.h"

inherit ARMOR;

void create()
{
        set_name("short plate","蜥蜴人短甲");
        add("id",({"plate"}) );
         set_short("蜥蜴人短甲");
	set_long(@LONG
普通蜥蜴人愛穿的短甲，好像某種獸麟製成的。
LONG
	);
	set( "unit", "件" );
	set( "weight", 75 );
	set( "type", "body" );
	set( "material", "leather" );
	set( "armor_class", 11 );
	set( "defense_bonus", 3 );
	set( "value", ({ 500, "silver" }) );
}
