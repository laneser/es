#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "key", "七彩鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "七彩鑰匙" );
	set_long(
		"這是一把七彩的鑰匙。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "TOMBKEY_2" );
	set( "weight", 5 );
	set( "value", ({ 100, "copper" }) );
	set( "no_sale", 1 );
}
