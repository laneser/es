#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Dragon ring","龍戒" );
     add( "id",({ "ring" }) );
     set_short( "龍戒" );
     set_long(@C_LONG
一隻水晶製成的小巧戒指，戒指上雕刻著一個龍頭。
C_LONG
     );
     set( "weight",20 );
     set( "unit", "只");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
}
