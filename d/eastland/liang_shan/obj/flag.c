#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "small flag", "令旗" );
	add( "id", ({ "flag" }) );
	set_short( "a small flag", "令旗" );
	set_long(
		"This is the flag of bandit trainer.\n",
		"這是一面指揮山賊的令旗，上面繡著替天行道的金字，如果有了它便可在\n"
		"梁山通行無阻。\n"
	);
	set( "weight", 3 );
	set( "value", ({ 3000, "silver" }) );
	set( "no_sale", 1 );
}
