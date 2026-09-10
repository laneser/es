#include "../echobomber.h"

inherit WEAPON;

void create()
{
   // seteuid(getuid());
	set_name("silver long spear", "銀長矛");
	add ("id",({ "spear" }) );
	set_short("銀長矛");
	set_long(
            "一把銀製的長矛\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 23 );
	set( "type", "thrusting" );
	set( "min_damage", 9 );
	set( "max_damage", 28 );
	set( "weight", 180 );
	set( "value", ({ 980, "silver" }) );
}

