#include <mudlib.h>
inherit ARMOR;

void create()
{
	set_name("platinum necklace", "白金項鍊");
add( "id", ({ "necklace" }) );
	set_short( "白金項鍊" );
        set_long(
@C_LONG
這條白金的項鍊看來價值不斐，是奇維送給佩蘿蒂絲的十八歲生日
禮物，由於鍛造工藝細膩，這是佩蘿蒂絲所喜愛的裝飾品。
C_LONG
        );
	set( "unit", "條");
        set( "type", "misc" );
	set( "material", "light_metal" );
   set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );                       
        set( "weight", 40 );
   set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1);
}
