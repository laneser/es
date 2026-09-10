#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril boots", "米蘇里戰靴");
        add( "id", ({ "boots" }) );
        set_short("a pair of mithril boots", "米蘇里戰靴");
        set_long(
                "A pair of boots made of mithril .\n",
                "一雙由米蘇里金屬造成的戰靴\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "light_metal" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 1450, "silver" }) );
}
