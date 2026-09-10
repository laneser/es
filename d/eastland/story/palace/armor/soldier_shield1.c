#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "silver shield","白銀盾牌" );
     add( "id",({ "shield" }) );
     set_short( "白銀盾牌" );
     set_long(@C_LONG
一件白銀製成的盾牌，不時在盾面閃耀著銀光，刺眼極了。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "shield" );
     set( "material","heavy_metal" );
     set( "armor_class",7 );
     set( "defense_bonus",4 );
     set( "value",({ 3500,"silver" }) );
}
