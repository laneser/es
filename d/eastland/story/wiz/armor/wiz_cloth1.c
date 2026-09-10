inherit ARMOR;
void create()
{
     set_name( "white cloth","白色官服" );
     add( "id",({ "cloth" }) );
     set_short( "白色官服" );
     set_long(@C_LONG
這是一件「巫咸國」裡尋常文官所穿的衣服，一襲純白，造形並不花俏。 
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "armor_class",26);
     set( "defense_bonus",5 );
     set( "value",({ 1000,"silver" }) );
}
