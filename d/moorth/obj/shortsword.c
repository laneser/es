#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "shortsword", "短劍" );
	add( "id", ({ "short sword", "sword" }) );
	set_short( "an alloyed shortsword", "合金短劍" );
	set_long(
		"You see a short sword made of some unknown alloyed metal.\n",
		"這是一把用某種合金鑄成的短劍，劍刃為亮銀色泛著紅色光澤。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 6 );
	set( "max_damage", 13 );
	set( "value", ({ 290, "silver" }) );
}
