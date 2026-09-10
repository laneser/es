inherit ARMOR;
void create()
{
     set_name( "fighter's leggings","戰士□脛甲" );
     add( "id",({ "leggings" }) );
     set_short( "戰士□脛甲" );
     set_long(@C_LONG
一件由「羽民族大首族  羽後」以天然礦石特製而成的脛甲，上面再加以防雷電咒
語，同時在內側縫有絲質布料，穿戴起來非常舒適。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "legs" );
     set( "material","element" );
     set( "armor_class",6 );
     set( "defense_bonus",3 );
     set( "value",({ 720,"silver" }) );
     set("special_defense",
         (["electric":5]) );
}