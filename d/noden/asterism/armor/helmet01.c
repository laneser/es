#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling helmet", "半身人頭盔");
        add( "id", ({ "helmet" }) );
        set_short( "半身人頭盔");
        set_long(
                "這是半身人守衛專用的頭盔 \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set("material","light_metal") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "weight", 70 );
        set( "value", ({ 135, "gold" }) );
}



