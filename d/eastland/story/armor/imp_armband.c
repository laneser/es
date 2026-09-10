inherit ARMOR;
void create()
{
     set_name( "fighter's armband","戰士□臂環" );
     add( "id",({ "armband" }) );
     set_short( "戰士□臂環" );
     set_long(@C_LONG
一雙由「羽民族大首領  羽後」用天然礦石製成的臂環，上面再加以防雷電咒語，
同時在臂環內側還有縫有絲質布料，穿戴起來非常舒適。
C_LONG
     );
     set( "unit","雙" );
     set( "weight",30 );
     set( "type","arms" );
     set( "material","element" );
     set( "armor_class",3 );
     set( "defense_bonus",4 );
     set( "value",({ 720,"silver" }) );
     set("special_defense",
        (["energy":-20,"electric":20]) );
}