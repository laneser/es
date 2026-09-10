#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "square cloth", "方布" );
	set_short( "方布" );
	set_long(
"這是一塊約有三尺見方大的布，上面還繡了許多圖案，看起來好像是天上仙境。\n"
	);
        add( "id", ({"cloth"}) );
	set( "no_sale", 1 );
	set( "unit", "塊" );
	set( "weight", 2 );
	set( "value", ({ 1, "silver" }) );
}
