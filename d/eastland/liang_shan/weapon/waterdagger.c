#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("smooth dagger", "分水蛾眉刺");
	add("id",({"dagger"}));
	set_short("smooth dagger", "分水蛾眉刺");
	set_long(
		"This is a sharp thin dagger\n",
		"這是一把鋒利的匕首，細長的刀刃似乎可以切斷水流。\n"
	);
	set( "unit", "把" );
	set( "weight", 90 );
	set( "type", "dagger" );
	set( "second",1);
	set( "weapon_class", 18 );
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "value", ({ 610, "silver" }) );
}
