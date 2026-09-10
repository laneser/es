#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("black silk-hood", "皂紗轉角簇花巾");
        add( "id", ({ "hood","silk-hood" }) );
        set_short( "black silk-hood", "皂紗轉角簇花巾");
        set_long(
                "A beautiful black silk hood .\n",
                "這是一頂黑紗頭巾，烏黑亮麗，閃閃動人． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":3, "acid":5, "mental":2 ]) );
        set( "weight", 50 );
        set( "value", ({ 306, "gold" }) );
}



