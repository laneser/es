#include <mudlib.h>
inherit ARMOR;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
        set_name( "Wooden plate", "木化鎧甲");
        add( "id", ({ "plate" }) );
        set_short("Wooden plate", "木化鎧甲");
        set_long(@AAA
這是一件以木質編織而成的鎧甲，顯的相當神奇有趣。
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 10 );
        set("material","wood");
        set("special_defense",(["electric":15])) ;
        set( "weight", 350 );
        set( "value", ({ 1000, "silver" }) );
}
