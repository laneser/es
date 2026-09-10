#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "Silver cape","繡絲曳尾雲肩" );
     add( "id",({ "cape" }) );
     set_short( "繡絲曳尾雲肩" );
     set_long(@C_LONG
一件手工細緻的絲質雲肩，後面尚拖著地面。
C_LONG
     );
     set( "weight",70 );
     set( "unit", "件");
     set( "type", "cloak" );
     set( "material","cloth" );
     set( "defense_bonus",10 );
     set( "value",({ 2500,"silver" }) );
}
