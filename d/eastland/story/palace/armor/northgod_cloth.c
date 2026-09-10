#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Crystal plate","水晶鎧甲" );
     add( "id",({ "plate" }) );
     set_short( "水晶鎧甲" );
     set_long(@C_LONG
一件水晶製成的鎧甲，表面卻如同鏡子一般，沒有任何紋路。
C_LONG
     );
     set( "weight",110 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",35 );
     set( "defense_bonus",8 );
     set( "value",({ 4000,"silver" }) );
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
}
int equip_cloth()
{
     this_player()->add_temp("can_pass_spell",1 );
     return 1;
}
int unequip_cloth()
{
     this_player()->add_temp("can_pass_spell",-1);
     return 1;
}