#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Orb amulet", "水晶護身符");
        add( "id", ({ "amulet" }) );
        set_short( "水晶護身符");
        set_long(
                "一個水晶護身符,水晶自古就含有極強魔力,經過地精神聖\n"
                "力量洗禮的水晶更是其中的極品。\n"
               );
        set("unit","個");
        set("material","element");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 10 );
        set( "weight", 5 );
        set( "value", ({ 100, "gold" }) );
}



