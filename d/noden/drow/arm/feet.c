#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper feet ring", "黃銅足環");
        add( "id", ({ "ring","boots" }) );
        set_short( "黃銅足環" );
        set_long(
@C_LONG
這是一對用黃銅打造的腳環，是黑暗精靈特有的產品，它能緊密的
扣住你的足踝，可以預防傷害。
C_LONG
        );
        set( "unit", "對");
        set( "type", "feet" );
   set( "material", "light_metal" );
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "weight", 70 );
        set( "value", ({ 260, "silver" }) );
}
