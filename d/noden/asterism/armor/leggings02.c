#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("bronze leggings", "青銅脛甲");
        add( "id", ({ "leggings" }) );
        set_short("青銅脛甲");
        set_long(
                "這是一雙青銅脛甲.\n"
        );
        set("unit","雙");
        set( "type", "legs" );
        set("material","light_metal") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 100 );
        set( "value", ({ 180, "gold" }) );
}






