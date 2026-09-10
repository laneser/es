#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("red armor","硃紅甲");
    add("id",({"armor"}) );
    set_short( "red armor","硃紅甲");
	set_long(
		"This is a red armor for warriors. \n",
		"一件硃紅的戰甲，看來品質還不錯．\n"
	);
	set( "unit", "件" );
	set( "weight", 75 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","light_metal");
	set( "defense_bonus", 3 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":4,"poison":1]));
}
