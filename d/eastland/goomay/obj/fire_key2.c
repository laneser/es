#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "fire key", "火焰之鑰" );
	add( "id", ({ "key" }) );
	set_short( "a fire key", "火焰之鑰" );
	set_long(
		"A magic key with fire shape.\n",
		"這是一個鑄成火焰形的鑰匙。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "FIRE_ELEMENT_KEY2" );
	set( "weight", 15 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
