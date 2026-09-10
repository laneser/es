#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "fruit_club", "小槌子" );
	set_short( "小槌子" );
	set_long(
		"這是專門用來敲人參果用的槌子。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "只" );
	set( "weight", 5 );
	set( "value", ({ 1, "silver" }) );
}
