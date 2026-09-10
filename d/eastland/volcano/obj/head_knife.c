#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "sharp knife", "銳利小刀" );
	set_short( "銳利小刀" );
	set_long(
		"這是一把專門用來割頭顱的小刀。\n"
	);
        add("id", ({"knife"}));
	set( "no_sale", 1 );
	set( "unit", "把" );
	set( "weight", 3 );
	set( "value", ({ 0, "silver" }) );
}
