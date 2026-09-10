#include <mudlib.h>
inherit ARMOR;
void create()
{
     set_name( "red cloth","大紅衣服" );
     add( "id",({ "cloth" }) );
     set_short( "大紅衣服" );
     set_long(@C_LONG
一件赤紅色的寬大衣服，兩個□肩高高的，穿起來蠻有威嚴。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",1 );
     set( "value",({ 400,"silver" }) );
     set("special_defense",
         (["electric":50]) );
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