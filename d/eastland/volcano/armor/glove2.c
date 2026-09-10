#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("worker's gloves", "工作手套");
        add( "id", ({ "gloves" }) );
        set_short("工作手套");
        set_long(
                "這是一雙工作手套，對雙手能提供很好的保護。\n"
        );
        set("unit","雙");
        set( "type", "hands" );
        set("material","cloth") ;
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 50 );
        set( "value", ({ 50, "gold" }) );
}






