#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril helmet", "米蘇理頭盔");
        add( "id", ({ "helmet" }) );
        set_short( "a mithril helmet", "米蘇理頭盔");
        set_long(
                "A large helmet made of mithril .\n",
                "這是用米蘇理金屬所製成的頭盔. \n"
                
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "weight", 66 );
        set( "value", ({ 1100, "silver" }) );
}



