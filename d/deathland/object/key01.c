#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "golden key", "金色鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "an golden key", "金色鑰匙" );
	set_long(
		"A golden key.\n",
		"這是一把金色的鑰匙,上面鑲滿了鑽石\n"
	);
	set( "unit", "把" );
	set( "to_lock", "ECHO_DWARF_CITY_1" );
	set( "weight", 3 );
	set( "value", ({ 120, "silver" }) );
	set( "no_sale", 1 );
}
