#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron cap", "沖天角鐵頭鏷");
        add( "id", ({ "cap" }) );
        set_short( "iron cap", "沖天角鐵頭鏷");
        set_long(
                "A iron cap .\n",
                "一頂很奇怪的金屬高帽子，戴起來有一點怪異．\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "adventurer");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 70 );
        set( "value", ({ 300, "gold" }) );
        set("extra_skills",(["whip":10]));
}



