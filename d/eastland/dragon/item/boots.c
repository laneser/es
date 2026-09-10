#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("golden boots", "黃金鞋");
        add( "id", ({ "boot","boots" }) );
        set_short("黃金鞋");
        set_long(
                "這是一雙用純金打造的鞋\n"
        );
        set("unit","雙");
        set( "type", "feet" );
        set( "material", "heavy_metal" );
        set( "armor_class", 8 );
        set( "weight", 100 );
        set( "value", ({ 150, "gold" }) );
}
