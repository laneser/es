#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("white robe","白緞子征衫");
    add("id",({"robe"}) );
    set_short( "white robe","白緞子征衫");
	set_long(
		"This is a white silk robe for warriors. \n",
		"征衫是戰士們出征時所穿的衣物，能穿到這種衣服代表武藝已達到\n"
		"一定的水準．這是用白緞子織成的征衣，雖經清洗，仍看出血跡斑斑．\n"
	);
	set( "unit", "件" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "armor_class", 18 );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 63, "gold" }) );
        set( "special_defense",(["none":5,"poison":1]));
}
