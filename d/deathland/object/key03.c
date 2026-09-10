#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "grey key", "灰色鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "a grey key", "灰色鑰匙" );
	set_long(
		"A grey key.\n",
		"這是一把灰色鑰匙,由於許久未使用所以原有的光澤完全消退了\n"
	);
	set( "unit", "把" );
	set( "to_lock", "ECHO_VILLAGE_ARCHDOOR" );
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
