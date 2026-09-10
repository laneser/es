#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "iron key", "鋼鑄鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "an iron key", "鋼鑄鑰匙" );
	set_long(
		"An ivory key with a large ruby on its handle.\n",
		"一把用鋼所淬鑄而成的鑰匙。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "WINEROOM_DOOR" );
	set( "weight", 3 );
	set( "value", ({ 40, "silver" }) );
	set( "no_sale", 1 );
}
