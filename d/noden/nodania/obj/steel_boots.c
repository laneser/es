#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel boots", "鋼戰靴" );
	add( "id", ({ "boots" }) );
	set_short( "鋼戰靴" );
	set_long(
		"這是一雙鋼製的戰靴。\n"
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "heavy_metal" );
	set( "armor_class", 7 );
	set( "weight", 50 );
	set( "value", ({ 1320, "silver" }) );
}
