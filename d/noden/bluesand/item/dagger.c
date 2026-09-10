#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long dagger", "長柄匕首" );
	add( "id", ({ "dagger" }) );
   set_short( "長柄匕首" );
	set_long(
		"一把長而鋒利的匕首，柄部為了方便揮動而加長。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weapon_class", 11 );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "bleeding", 5 );
	set( "weight", 35 );
	set( "value", ({ 170, "silver" }) );
}
