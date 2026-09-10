#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name( "warlord shield", "戰神盾牌");
        add( "id", ({ "shield" }) );
        set_short("a warlord shield", "戰神盾牌");
        set_long(
                "mithril shield of protection .\n",
           "這是用米蘇里金屬與銀混合所製成的盾，由歷代的矮人將軍一直傳下來 \n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus",3 );
        set( "weight", 100 );
        set( "value", ({ 350, "gold" }) );
}






