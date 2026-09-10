#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long spear", "長矛" );
	add( "id", ({ "spear" }) );
	set_short( "長矛" );
	set_long(
		"這根長矛是用一枝長木棍，在末端綁上一塊尖銳的岩石碎片製成。\n"
	);
	set( "unit", "枝" );
	set( "weight", 90 );
	set( "type", "thrusting" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 14 );
	set( "value", ({ 180, "silver" }) );
}
