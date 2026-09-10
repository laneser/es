#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "yoroi", "戰甲" );
   set_short( "日式戰甲" );
	set_long(
     "這是一套日式的鎧甲，將許多硬化的牛皮用粗繩結起來，然後在重要\n"
		"的部位打上金屬片。\n"
	);
	set( "unit", "套" );
	set( "weight", 210 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 25 );
	set( "defense_bonus", 3 );
    set( "special_defense",
           ([ "electric":-3, "acid":2 ]) );
	
	set( "value", ({ 820, "silver" }) );
	set( "no_sale", 1 );
}
