#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed shield", "合金盾" );
	add( "id", ({ "shield" }) );
	set_short( "an alloyed shield", "合金盾" );
	set_long(
		"You see an alloyed shield. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"這是一面用某種不知名合金打造的盾，看起來相當重。\n"
	);
	set( "unit", "面" );
	set( "type", "shield" );
	set( "material", "heavy" );
	set( "armor_class", 6 );
	set( "weight", 140 );
	set( "value", ({ 630, "silver" }) );
}
