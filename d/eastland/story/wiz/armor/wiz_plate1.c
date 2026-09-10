inherit ARMOR;
void create()
{
     set_name( "golden plate","黃金鎧甲" );
     add( "id",({ "plate","cloth" }) );
     set_short( "黃金鎧甲" );
     set_long(@C_LONG
一件純金打造的鎧甲，金光閃閃相當昂貴。
C_LONG
     );
     set( "weight",250 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","heavy_metal" );
     set( "armor_class",34);
     set( "defense_bonus",5 );
     set( "value",({ 2500,"silver" }) );
}