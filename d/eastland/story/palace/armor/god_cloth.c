#include "../../story.h"

inherit ARMOR;
inherit SARM"OR";
void create()
{
     set_name( "God-Dragon plate","界龍鎧甲" );
     add( "id",({ "plate" }) );
     set_short( "界龍鎧甲" );
     set_long(@C_LONG
一件前面刻畫著飛龍的鎧甲，全身亮晶晶，令人愛不釋手。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",26 );
     set( "defense_bonus",5 );
     set( "the_one",1);
     set( "value",({ 3000,"silver" }) );
}
