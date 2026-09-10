#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "etheral cutlass", "地獄彎刀" );
	add( "id", ({ "cutlass" }) );
   set_short( "地獄彎刀" );
	set_long(
		"一把閃爍著幽暗光暈的彎刀，拿在手上輕飄飄的，感覺不到重量。\n"
	);
	set( "unit", "把" );
   set( "type", "shortblade" );
	set( "weapon_class", 21 );
	set( "min_damage", 9 );
	set( "max_damage", 16 );
	set( "weight", 5 );
	set( "value", ({ 320, "silver" }) );
}
