#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "silver plate","白銀鎧甲" );
     add( "id",({ "plate" }) );
     set_short( "白銀鎧甲" );
     set_long(@C_LONG
一件白銀製成的鎧甲，造型別致，穿起來英挺極了。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","heavy_metal" );
     set( "armor_class",34 );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
}
