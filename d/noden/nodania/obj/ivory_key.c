#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "ivory key", "象牙鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "an ivory key", "象牙鑰匙" );
	set_long(
		"An ivory key with a large ruby on its handle.\n",
		"一把用象牙雕刻成的鑰匙，在鑰匙的柄部還鑲著一粒紅寶石。\n"
	);
	set( "unit", "把" );
	set( "to_lock", "KING_YARAMON_XI_LIBRARY" );
	set( "weight", 3 );
	set( "value", ({ 40, "silver" }) );
	set( "no_sale", 1 );
}
