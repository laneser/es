#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson robe", "鮮紅色護袍" );
	set_short( "鮮紅色護袍" );
	set_long(@CLONG
這是一件用鮮紅色布料做成的護袍，在護袍的背面畫滿了許多奇異的\n"
符號，看起來十分詭異 ....\n"
CLONG
         	);
	add("id",({"robe"}));
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 4 );
    set( "special_defense",
          ([ "evil":5, "mental":-3, "divine":-5 ]) );
	set( "weight", 90 );
	set( "value", ({ 470, "silver" }) );
}
