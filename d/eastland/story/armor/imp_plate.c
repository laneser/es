inherit ARMOR;
void create()
{
     set_name( "fighter's plate","戰士□鎧甲" );
     add( "id",({ "plate","cloth" }) );
     set_short( "戰士□鎧甲" );
     set_long(@C_LONG
一件由「羽民族大首領  羽後」以天然礦石特製而成的鎧甲，上面再加以防雷電咒
語，並在其內側縫有絲質布料，穿戴起來非常舒適。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","element" );
     set( "armor_class",27 );
     set( "defense_bonus",4 );
     set( "value",({ 1220,"silver" }) );
}