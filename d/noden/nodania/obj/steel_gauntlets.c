#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel gauntlets", "鋼手套" );
	add( "id", ({ "gauntlets" }) );
	set_short( "鋼手套" );
	set_long(
		"這是一雙鋼製的手套。\n"
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "material", "heavy_metal" );
	set( "armor_class", 4 );
	set( "weight", 50 );
	set( "value", ({ 880, "silver" }) );
}
