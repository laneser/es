#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Westgod's helmet","@@query_short" );
     add( "id",({ "helmet", }) );
     set_short( "@@query_short" );
     set_long(@C_LONG
一頂金澄澄的頭冠，上面鑲有各色珠寶，耀眼生輝。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "頂");
     set( "type", "head" );
     set( "material","heavy_metal" );
     set( "armor_class",8 );
     set( "defense_bonus",3 );
     set( "value",({ 3000,"silver" }) );
     set( "special_defense",(["divine":10]));
}
string query_short()
{
       return set_color("星天冠","HIY") ;
}