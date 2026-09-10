#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "guardroom key", "看守室鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "看守室鑰匙" );
	set_long(
		"這是矮靈族看守室的鑰匙。\n"
	);
	set( "to_lock", "WGUARD" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
