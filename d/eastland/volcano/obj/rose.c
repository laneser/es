#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "blue rose", "藍玫瑰" );
	set_short( "藍玫瑰" );
        add ( "id" , ({"rose"}) );
	set_long(
	  "這是一朵世上罕有的藍色玫瑰花。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "朵" );
	set( "weight", 2 );
	set( "value", ({ 1, "gold" }) );
}
