#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "rusty longsword", "鏽劍" );
	add( "id", ({ "longsword", "sword" }) );
  set_short( "生鏽長劍" );
	set_long(
		"這把長劍已經生滿了鏽，不過看起來似乎還能當作武器。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 9 );
	set( "min_damage", 5 );
	set( "max_damage", 13 );
	set( "value", ({ 105, "silver" }) );
}
