#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Hell Blessed suit","幽冥之袍" );
        add( "id", ({ "suit","cloth" }) );
        set_short( "幽冥之袍" );
        set_long(
                "你看到這件袍子上面寫了幾個字: 黑帝斯出品，品質保證。\n"
        );
        set( "unit", "領" );
        set("material","cloth");
        set( "type", "body" );
        set( "armor_class", 33 );
        set( "defense_bonus", 5 );
        set( "weight", 70 );
        set( "value", ({ 1700, "silver" }) );
}
