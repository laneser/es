#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("bronze ringmail", "青銅環甲");
        add( "id", ({ "ringmail","mail" }) );
        set_short( "青銅環甲");
        set_long(
                "這是一件青銅製的環甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","light_metal");
        set( "armor_class", 26 );
        set( "defense_bonus", 0 );
        set( "weight", 300 );
        set( "value", ({ 210, "gold" }) );
}






