#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks mail", "火山岩鱗甲");
        add( "id", ({ "mail" }) );
        set_short( "火山岩鱗甲");
        set_long(
                "這件鱗甲乃是用火山岩製成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 13 );
        set( "weight", 270 );
        set( "value", ({ 100, "gold" }) );
}






