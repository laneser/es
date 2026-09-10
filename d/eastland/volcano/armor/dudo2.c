#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("blue du-do", "藍色肚兜");
        add( "id", ({ "du-do" }) );
        set_short( "藍色肚兜");
        set_long(
                "這件肚兜是矮靈族小男孩在穿的。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 8 );
        set( "weight", 100 );
        set( "value", ({ 10, "gold" }) );
}






