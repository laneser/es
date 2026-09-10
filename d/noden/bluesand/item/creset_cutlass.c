#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "creset cutlass", "新月彎刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "新月彎刀" );
	set_long(
		"一把長而精緻的彎刀，它看起來十分銳利，刀背上刻著十三個新月的刻痕。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 25 );
	set( "min_damage", 8 );
	set( "max_damage", 20 );
	set( "bleeding", 15 );
	set( "weight", 80 );
	set( "value", ({ 1460, "silver" }) );
}
