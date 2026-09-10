#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "silver tail", "亮銀尾甲" );
        add( "id", ({ "tail" }) );
        set_short( "亮銀尾甲" );
        set_long(@C_LONG
一個閃閃發光的銀製尾甲。雕工精細，看起來相當名貴。
C_LONG
        );
        set( "unit", "件");
        set( "type", "tail" );
        set( "material", "heavy_metal");
        set( "armor_class",3 );
        set( "defense_bonus", 1 );
        set( "weight", 80 );
        set( "value", ({ 350, "gold" }) );
}
