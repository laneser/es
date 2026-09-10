#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "spear", "長矛" );
	set_short( "a hunting spear", "狩獵用長矛" );
	set_long(
		"A long spear designed for hunting boars.\n",
		"一把用來獵殺野豬用的長矛。\n"
	);
	set( "weapon_class", 6 );
	set( "type", "thrusting" );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "weight", 40 );
	set( "value", ({ 15, "gold" }) );
}
