#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "oregon ring", "俄勒岡的戒指" );
	add( "id", ({ "ring" }) );
	set_short( "俄勒岡的戒指" );
	set_long(
		"這是俄勒岡的戒指。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "只" );
	set( "weight", 3 );
	set( "value", ({ 1, "silver" }) );
}
