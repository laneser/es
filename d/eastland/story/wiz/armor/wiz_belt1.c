inherit ARMOR;
void create()
{
     set_name( "white belt","白練腰帶" );
     add( "id",({ "belt" }) );
     set_short( "白練腰帶" );
     set_long(@C_LONG
一件純白色的腰帶，為「巫咸國」裡所文官慣穿。這腰帶是用天然布料做成的，觸
感還不錯。
C_LONG
     );
     set( "unit","件" );
     set( "weight",60 );
     set( "type","legs" );
     set( "material","cloth" );
     set( "armor_class",6 );
     set( "defense_bonus",5 );
     set( "value",({ 720,"silver" }) );
}