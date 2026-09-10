#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel shield", "鋼盾" );
	add( "id", ({ "shield" }) );
	set_short( "鋼盾" );
	set_long(
		"一面擦得閃亮耀眼的鋼盾。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 100 );
	set( "value", ({ 1130, "silver" }) );
}
