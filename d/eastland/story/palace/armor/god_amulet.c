#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon amulet","潛龍符" );
     add( "id",({ "amulet" }) );
     set_short( "潛龍符" );
     set_long(@C_LONG
一個白玉做的玉佩，上刻一隻盤旋於天際的飛龍，形狀甚是兇猛。
C_LONG
     );
     set( "weight",5 );
     set( "unit", "個");
     set( "type", "misc" );
     set( "material","element" );
     set( "the_one",1);
     set( "defense_bonus",5 );
     set( "value",({ 1000,"silver" }) );
}
