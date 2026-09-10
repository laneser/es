#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "crimson ring", "鮮紅色戒指" );
	add( "id", ({ "ring" }) );
	set_short( "鮮紅色戒指" );
	set_long(
		"這是一個鮮紅色金屬戒指，上面鑲著一顆紅寶石。\n"
	);
	set( "type", "finger" );
	set( "material", "element");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "special_defense",
		([ "evil":5, "electric":5,"divine":-7,"none": -5 ]) );
	set( "weight", 10 );
	set( "value", ({ 920, "silver" }) );
	set( "no_sale", 1 );
}
