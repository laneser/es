#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling ringmail", "半身人環甲");
        add( "id", ({ "ringmail","mail" }) );
        set_short("半身人環甲");
        set_long(
                "這是半身人守衛所專用的環甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set("material","light_metal");
        set( "armor_class", 25 );
        set( "defense_bonus", 2 );
        set( "weight", 250 );
        set( "value", ({ 200, "gold" }) );
}






