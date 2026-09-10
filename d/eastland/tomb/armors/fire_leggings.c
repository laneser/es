#include "../almuhara.h"
inherit ARMOR;

void create()
{
        set_name( "fire leggings", "火焰脛甲");
        add( "id", ({ "leggings" }) );
        set_short( "火焰脛甲");
        set_long(
                "這是火之護衛所穿的脛甲，有股亮紅色的光芒。\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "leather" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":5, "cold":-10 ]) );
        set( "extra_stats",(["con":-1]) );       
        set( "extra_skills", (["block": 15]) );
        set( "weight", 50 );
        set( "value", ({ 180, "gold" }) );
}
