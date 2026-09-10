#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "short sword", "短劍" );
	add( "id", ({ "sword" }) );
   set_short( "短劍" );
	set_long(
		"一把薄而鋒利短劍的短劍，用來當作防身武器。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weapon_class", 8 );
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set( "weight", 30 );
	set( "value", ({ 75, "silver" }) );
}
