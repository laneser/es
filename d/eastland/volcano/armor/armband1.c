#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("prayer armband", "祈禱者手環");
        add( "id", ({ "armband" }) );
        set_short("祈禱者手環");
        set_long(
                "這是一般祈禱者用的手環。\n"
        );
        set("unit","只");
        set( "type", "arms" );
        set( "material", "light_metal");
        set( "armor_class", 2 );
        set( "weight", 70 );
        set( "value", ({ 20, "gold" }) );
}






