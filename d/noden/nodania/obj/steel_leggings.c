#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel leggings", "鋼護膝" );
	add( "id", ({ "leggings" }) );
	set_short( "鋼護膝" );
	set_long(
		"這是一個鋼製的護膝。\n"
	);
	set( "unit", "副" );
	set( "type", "legs" );
	set( "material", "heavy_metal" );
	set( "armor_class", 8 );
	set( "weight", 100 );
	set( "value", ({ 1520, "silver" }) );
}
