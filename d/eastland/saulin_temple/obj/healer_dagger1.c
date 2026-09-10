#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "thin dagger","蟬翼薄刃");
	add( "id", ({ "dagger" }) );
	set_short( "蟬翼薄刃" );
	set_long(
		"這是一把極薄極窄的匕首, 薄如蟬翼, 卻又鋒利的緊。\n" 
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weight", 40 );
	set( "weapon_class", 30 );
	set( "min_damage", 13 );
	set( "max_damage", 26 );
	set( "value", ({ 1500, "silver" }) );
}
