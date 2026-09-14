#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("hammer", "鐵錘");
	set_short("an iron hammer", "鐵錘");
	set_long(
		"This is a regular hammer for blacksmith.\n",
		"這把鐵錘是一般鐵匠用來打鐵用的。\n"
	);
	set( "unit", "把" );
	set( "weight", 80 );
	set( "type", "blunt" );
	set( "weapon_class", 6 );
	set( "min_damage", 4 );
	set( "max_damage", 11 );
	set( "value", ({ 30, "silver" }) );
}
