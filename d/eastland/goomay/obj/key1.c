#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "iron key", "鐵鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "an iron key", "鐵鑰匙" );
	set_long(
		"A rusty iron key.\n",
		"這是一把有些生繡的鐵鑰匙，看起來好像是鎖牢門的。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "JAIL_DOOR" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
