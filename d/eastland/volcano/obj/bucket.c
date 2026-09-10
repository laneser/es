#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "bucket", "大水桶" );
	set_short( "大水桶" );
	set_long(
		"這是神殿內用來澆菜用的大水桶，非常大，甚至人可以坐在裡面。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "只" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
