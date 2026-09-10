#include "mudlib.h"

inherit OBJECT;

void create()
{
	set_name( "steel seal", "精鋼封印" );
	add( "id", ({ "key","seal" }) );
	set_short( "a steel seal", "精鋼封印" );
	set_long(
		"A magic seal made by high steel.\n",
		"這是一個鑄成火焰形的純鋼封印，好像可以□入某個門裡。\n"
	);
	set( "unit", "塊" );
	set( "to_lock", "FIRE_ELEMENT_KEY" );
	set( "weight", 15 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
