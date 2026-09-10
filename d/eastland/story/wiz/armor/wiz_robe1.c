inherit ARMOR;
void create()
{
     set_name( "The Archmaster's robe","護國師□袍" );
     add( "id",({ "robe" }) );
     set_short( "護國師□袍" );
     set_long(@C_LONG
一件繡著白雲圖案的絲制袍子。在這件袍子上還有著天神的祝福，在白雲裡不時有
五色祥光出現。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "armor_class",30);
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
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