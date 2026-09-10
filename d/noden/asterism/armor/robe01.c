#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("holy robe", "聖袍");
        add( "id", ({ "robe" }) );
        set_short( "聖袍");
        set_long(
                "這是一件被附與地精神聖力量的法袍。整件衣服上閃耀著金色的符號。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","cloth");
        set( "armor_class", 35 );
        set( "defense_bonus", 5 );
        set("special_defense",
              (["fire":10,"cold":-10,"evil":15,"divine":-15,"magic":10]) );
        set( "weight", 170 );
        set( "value", ({ 220, "gold" }) );
}


