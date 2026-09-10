#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "diamond key", "鑽石鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "鑽石鑰匙" );
	set_long(
		"這是用鑽石琢磨出來的鑰匙。\n"
	);
	set( "to_lock", "DIAMONDKEY" );
	set( "weight", 3 );
	set( "value", ({ 50, "silver" }) );
	set( "no_sale", 1 );
}
