#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long cutlass", "長彎刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "長彎刀" );
	set_long(
		"一把長而精緻的彎刀，它看起來十分銳利。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 18 );
	set( "min_damage", 10 );
	set( "max_damage", 17 );
	set( "weight", 70 );
	set( "value", ({ 320, "silver" }) );
}
