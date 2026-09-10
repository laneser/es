#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril leggings", "米蘇里脛甲");
        add( "id", ({"leggings" }) );
        set_short("a pair of mithril and silver leggings", "銀米蘇里脛甲");
        set_long(
                "A pair of leggings made of mithril and silver.\n",
                "一雙由米蘇里金屬與銀造成的脛甲\n"
        );
        set( "unit", "雙");
        set( "type", "legs" );
        set( "material", "heavy_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "weight", 150 );
        set( "value", ({ 950, "silver" }) );
}
