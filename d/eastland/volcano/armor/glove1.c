#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("wraith gloves", "矮靈手套");
        add( "id", ({ "gloves" }) );
        set_short("矮靈手套");
        set_long(
                "這是一雙矮靈長老手套。\n"
        );
        set("unit","雙");
        set( "type", "hands" );
        set("material","element") ;
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set( "weight", 60 );
        set( "value", ({ 70, "gold" }) );
}






