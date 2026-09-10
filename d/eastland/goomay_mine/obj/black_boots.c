#include "../zeus.h"
inherit ARMOR;

void create()
{
        set_name("daemonic boots", "黑色怪鞋");
        add( "id", ({ "boots" }) );
        set_short("daemonic boots", "黑色怪鞋");
        set_long(@CLONG
這是一雙黑色的怪鞋，看不出是什麼做成的，不過似乎隱藏了一股
莫名的力量
CLONG
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "special_defense",
               (["acid":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 440, "silver" }) );
}