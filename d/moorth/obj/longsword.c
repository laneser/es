#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "longsword", "長劍" );
	add( "id", ({ "long sword", "sword" }) );
	set_short( "an alloyed longsword", "合金長劍" );
	set_long(
		"You see a long sword made of some unknown alloyed metal.\n",
		"這是一把用某種合金鑄成的長劍，劍刃為亮銀色泛著紅色光澤。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 21 );
	set( "min_damage", 9 );
	set( "max_damage", 19 );
	set( "value", ({ 470, "silver" }) );
}
