#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("golden shield","黃金盾");
        add( "id", ({ "shield" }) );
        set_short( "黃金盾");
        set_long(@C_LONG
一面用18K金做成的盾牌，這只有「巫咸國」的人才用的起這樣昂貴的盾牌。
C_LONG
        );
        set( "unit","面");
        set( "type", "shield" );
        set( "material","heavy_metal");
        set( "armor_class",7 );
        set( "defense_bonus", 4 );
        set( "weight", 150 );
        set( "value", ({ 2000, "silver" }) );
}



