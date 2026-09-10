#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "eight belt", "八卦陰陽帶" );
        add( "id", ({ "belt" }) );
        set_short( "八卦陰陽帶" );
        set_long(@C_LONG
一件繡著八卦圖形的腰帶。
C_LONG
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set("special_defense",(["magic":15,"evil":-20]) );
        set( "value", ({ 150, "gold" }) );
}
