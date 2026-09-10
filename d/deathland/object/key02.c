#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "skeleton key", "骨鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "a skeleton key", "骨鑰匙" );
	set_long(
		"A skelton key.\n",
		"這是一把骨頭鑰匙,上面寫滿了一堆符號\n"
	);
	set( "unit", "把" );
	set( "to_lock", "ECHO_MINE_CHEST" );
	set( "weight", 5 );
	set( "value", ({ 120, "silver" }) );
	set( "no_sale", 1 );
}
