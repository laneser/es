#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black mithril leggings", "黑色米蘇理護膝");
        add( "id", ({"leggings" }) );
        set_short("a pair of black mithril leggings", "黑色米蘇理護膝");
        set_long(
                "A pair of leggings made of mithril and some mystic metal.\n",
                "一雙由米蘇里與某種神秘的金屬造成的脛護膝\n"
        );
       // set("no_sale",1);
        set( "unit", "雙");
        set( "type", "legs" );
        set( "material", "heavy_metal" );
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "weight", 100 );
        set( "value", ({ 5700, "silver" }) );
}
