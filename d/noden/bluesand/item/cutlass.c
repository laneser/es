#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "cutlass", "彎刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "彎刀" );
	set_long(
		"一把精緻的彎刀，它看起來十分銳利。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 15 );
	set( "min_damage", 10 );
	set( "max_damage", 14 );
	set( "weight", 70 );
	set( "value", ({ 420, "silver" }) );
}
