#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "fruit_cloth", "布" );
	set_short( "布" );
	set_long(
		"這是專門鋪在人參果樹下接果子所用的布。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "塊" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
