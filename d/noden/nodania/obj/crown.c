#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("crown", "王冠");
	set_short("黃金王冠");
	set_long(
    "這是一頂純金打造的王冠，上面鑲著許多珍珠瑪瑙，看起來十分名貴。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material", "heavy_metal");
	set( "armor_class", 3 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "fire":5, "cold":-8, "mental":5, "energy":-6 ]) );
	set( "value", ({ 3100, "gold" }) );
	set( "weight", 40 );
	set( "no_sale", 1);
}
