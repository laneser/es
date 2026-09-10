#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("holy leggings", "神聖脛甲");
        add( "id", ({"leggings" }) );
        set_short("a pair of holy leggings", "神聖脛甲");
        set_long(
                "A pair of leggings enchanted holy power.\n",
                "一雙有著神聖力量的脛甲\n"
        );
        set( "unit", "雙");
        set( "type", "legs" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "special_defense", ([ "divine":5, "none":-3 ]) );
        set( "weight", 140 );
        set( "value", ({ 2000, "silver" }) );
}
