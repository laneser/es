#include "../farwind.h"

inherit WEAPON;

void create()
{
	set_name("heavy broadsword", "闊劍");
	add( "id", ({ "sword", "broadsword" }) );
	set_short("重型闊劍");
	set_long(
		"一把又長、又重而且鋒利的闊劍，屬於遠風鎮的保安官所有。\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 25 );
	set( "type", "longblade" );
	set( "min_damage", 13 );
	set( "max_damage", 28 );
	set( "bleeding", 10 );
	set( "weight", 160 );
	set( "nosecond", 1 );
	set( "value", ({ 66, "gold" }) );
}
