#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("huge mithril helmet", "巨米蘇理頭盔");
        add( "id", ({ "helmet" }) );
        set_short( "a mithril helmet", "巨米蘇理頭盔");
        set_long(
                "A huge helmet made of mithril .\n",
                "這是用米蘇理金屬所製成的頭盔. \n"
                
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 80 );
        set( "value", ({ 1800, "silver" }) );
}



