#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("Copper shield", "銅盾");
        add( "id", ({ "shield" }) );
        set_short( "銅盾" );
        set_long(
@C_LONG
這是銅製的盾牌，看來堅實厚重。
C_LONG
        );
        set( "unit", "面");
        set( "type", "shield" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 140 );
        set( "value", ({ 380, "silver" }) );
}
