#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "small club", "小槌子" );
	set_short( "小槌子" );
	set_long(
"一隻小木槌，奇怪的是在槌子的最前端有包著一層厚厚、柔軟的東西。\n"
	);
        add( "id", ({"club"}) );
	set( "no_sale", 1 );
	set( "unit", "只" );
	set( "weight", 5 );
	set( "value", ({ 1, "silver" }) );
}
