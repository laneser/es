#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("white lead gloves", "白鉛手套");
        add( "id", ({ "gloves" }) );
        set_short( "白鉛手套");
        set_long(
                "這是一雙由白鉛製的手套。\n"
        );
        set("unit","雙");
        set( "type", "hands" );
        set("material","light_metal");
        set( "armor_class", 2 );
        set( "defense_bonus", 2 );
        set( "weight", 60 );
        set( "value", ({ 56, "gold" }) );
}






