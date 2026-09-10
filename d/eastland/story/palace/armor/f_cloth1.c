#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Yellow cloth","淺黃色宮裝" );
     add( "id",({ "cloth" }) );
     set_short( "淺黃色宮裝" );
     set_long(@C_LONG
一色淺黃色的宮裝，薄如蟬翼。
C_LONG
     );
     set( "weight",100 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",5 );
     set( "value",({ 500,"silver" }) );
}
