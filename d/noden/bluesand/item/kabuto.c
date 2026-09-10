#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "kabuto", "頭盔" );
   set_short( "日式頭盔" );
	set_long(
		"這是一頂日式的頭盔，上面有一對黃銅做成的鹿角飾。\n"
	);
	set( "unit", "頂" );
	set( "weight", 80 );
	set( "type", "head" );
	set( "material", "light_metal");
	set( "armor_class", 5 );
	set( "defense_bonus", 3 );
	set( "special_defense",
	       ([ "mental":3, "electric":-3, "acid":1 ]) );
	          
	set( "value", ({ 575, "silver" }) );
	set( "no_sale", 1 );
}
