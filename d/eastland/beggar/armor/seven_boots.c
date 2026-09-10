#include "../dony.h"

inherit ARMOR;

void create()
{
     set_name("rainbow boots","七彩雲靴");
     add( "id", ({ "boots" }) );
     set_short( "七彩雲靴" );
     set_long(@C_TOPIC
七彩雲靴是用高級的綢緞做成的,上面因繡有彩虹的圖形而命名的。
C_TOPIC
              );
     set( "unit", "雙" );
     set( "type", "feet" );
     set( "material", "cloth" );
     set( "armor_class", 7 );
     set( "defense_bonus", 5 );
     set( "weight", 40 );
     set( "value", ({ 300, "silver" }) );
}