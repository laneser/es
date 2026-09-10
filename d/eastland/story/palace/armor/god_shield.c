#include <mudlib.h>

inherit ARMOR;
void create()
{
     set_name( "God-Dragon shield","升龍盾" );
     add( "id",({ "shield" }) );
     set_short( "升龍盾" );
     set_long(@C_LONG
一面擦拭的很乾淨的盾牌，上繪一雙張牙舞爪的飛龍，栩栩如生。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "面");
     set( "type", "shield" );
     set( "material","element" );
     set( "armor_class",7 );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
}
int equip_cloth()
{
    set("light",1);
    this_player()->add_temp("can_pass_spell",1 );
    return 1;
}
int unequip_cloth()
{
    delete("light");
    this_player()->add_temp("can_pass_spell",-1);
    return 1;
}