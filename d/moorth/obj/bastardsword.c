#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastardsword", "巨劍" );
	add( "id", ({ "bastard sword", "sword" }) );
	set_short( "an alloyed bastardsword", "合金巨劍" );
	set_long(
		"You see a bastard sword made of some unknown alloyed metal.\n",
		"這是一把用某種合金鑄成的重型劍，劍刃為亮銀色泛著紅色光澤。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 160 );
	set( "nosecond", 1 );
	set( "weapon_class", 29 );
	set( "min_damage", 11 );
	set( "max_damage", 26 );
	set( "value", ({ 750, "silver" }) );
}
