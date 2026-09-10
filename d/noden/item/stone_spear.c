#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "stone spear", "石鏃矛" );
	add( "id", ({ "spear" }) );
   set_short( "石鏃矛" );
	set_long(
		"一把木質長柄的矛，它的尖端是用石頭磨尖而成的。\n"
	);
	set( "unit", "把" );
	set( "type", "polearm" );
	set( "weapon_class", 13 );
	set( "min_damage", 6 );
	set( "max_damage", 15 );
	set( "weight", 70 );
	set( "value", ({ 120, "silver" }) );
}
