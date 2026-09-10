#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("green shining ring", "綠色閃亮戒指");
        add( "id", ({ "ring" }) );
        set_short( "綠色閃亮戒指");
        set_long(
                " 一個閃閃發光的綠色戒指\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "weight", 15 );
        set( "value", ({ 77, "gold" }) );
}



