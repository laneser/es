#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("enforcer's robe", "執事之袍");
        add( "id", ({ "robe" }) );
        set_short("執事之袍");
        set_long(
                "這件長袍是執事常穿著的。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "cloth");
        set( "armor_class", 13 );
        set( "weight", 160 );
        set( "value", ({ 40, "gold" }) );
}






