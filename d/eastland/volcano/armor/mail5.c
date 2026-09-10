#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks plate", "火山岩鎧冑");
        add( "id", ({ "plate" }) );
        set_short( "火山岩鎧冑");
        set_long(
                "這件鎧冑乃是用火山岩製成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 28 );
        set( "special_defense", ([ "fire":10 , "cold":-5 ]) );
        set( "weight", 330 );
        set( "value", ({ 160, "gold" }) );
}






