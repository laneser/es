#include "../dony.h"

inherit ARMOR;
void create()
{
     set_name( "fire armband","火雲護臂" );
     add( "id",({ "armband" }) );
     set_short( "火雲護臂" );
     set_long(@C_LONG
這是一個刻有火焰貌的臂環。上面的火焰捲曲成一片片的浮雲,浮雲圍繞的樣子甚
為兇猛。浮雲裡,隱隱間好像有一支蓄勢待發昇天的火龍, 更增添了護臂無比威嚴
貌。
C_LONG
     );
     set( "unit","雙" );
     set( "weight",30 );
     set( "type","arms" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",4 );
     set( "value",({ 620,"silver" }) );
}