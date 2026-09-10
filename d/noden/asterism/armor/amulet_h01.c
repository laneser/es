#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Shinning amulet", "閃閃發光的護身符");
        add( "id", ({ "amulet" }) );
        set_short( "閃閃發光的護身符");
        set_long(
                " 一個閃閃發光的護身符\n"
        );
        set("unit","個");
        set( "type", "misc" );
        set("material","cloth") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 15 );
        set( "value", ({ 122, "gold" }) );
}



