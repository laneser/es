#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Lu-Wu's ring","陸吾之戒" );
     add( "id",({ "ring" }) );
     set_short( "陸吾之戒" );
     set_long(@C_LONG
一隻黃澄澄的戒指，上面刻著陸吾的肖像。
C_LONG
     );
     set( "weight",5 );
     set( "unit", "只");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",5 );
     set( "value",({ 800,"silver" }) );
     set( "special_defense",(["poison":30,"evil":30,"divine":-30,"fire":-50]));
}
