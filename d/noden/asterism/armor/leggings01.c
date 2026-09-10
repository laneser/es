#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("brass leggings", "黃銅脛甲");
        add( "id", ({ "leggings" }) );
        set_short("黃銅脛甲");
        set_long(
                "這是一雙黃銅脛甲.\n"
        );
        set("unit","雙");
        set( "type", "legs" );
        set("material","light_metal") ;
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "weight", 110 );
        set( "value", ({ 70, "gold" }) );
}






