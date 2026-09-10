#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "flinty large sword", "燧石巨劍" );
	add( "id", ({ "sword" }) );
	set_short( "燧石巨劍" );
	set_long(
		"這是一把用暗紅色燧石做成的的巨劍，若非具有天賦神力
的人是拿不動的。\n" );
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 160 );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 28 );
	set( "value", ({ 950, "silver" }) );
}


