#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind helmet", "束雲頭帶");
        add( "id", ({ "helmet" }) );
        set_short( "束雲頭帶");
        set_long(@C_LONG
束雲頭帶是由震八方妻子由天然蠶絲編制而成的。是震八方最心愛的頭帶。
C_LONG
        );
        set("unit","頂");
        set( "type", "head" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "weight", 40 );
        set( "value", ({ 200, "gold" }) );
}



