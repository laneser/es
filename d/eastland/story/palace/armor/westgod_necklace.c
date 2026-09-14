#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Westgod's necklace","@@query_short" );
     add( "id",({ "necklace" }) );
     set_short( "@@query_short" );
     set_long(@C_LONG
一個純金打造，刻著龍的形狀的項鍊，價值不菲。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "個");
     set( "type", "misc" );
     set( "material","heavy_metal" );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
}
string query_short()
{
    return set_color("龍形項鍊","HIY");
}