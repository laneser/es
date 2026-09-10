#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Dragon plate","火神龍銀甲");
    add("id",({"plate","dragon"}) );
    set_short( "dragon plate","火神龍銀甲");
	set_long(
		"This is a suit of mail made of iron meterial.\n",
		"這是一件金光閃閃的巨型戰甲，其上有一巨大的龍紋，似乎有\n"
		"古火神龍力量保護，一層寒氣籠罩，對於炎熱似乎有特殊防護。\n"
	);
	set( "unit", "件" );
	set( "weight", 666 );
	set( "type", "body" );
	set( "armor_class", 35 );
        set("material","heavy_metal");
	set( "defense_bonus", 10 );
	set( "value", ({ 666, "gold" }) );
        set( "special_defense",(["ire":15,"evil":10]));
                                    
}
