#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "dragon_box", "黑龍的盒子" );
	set_short(  "黑龍的盒子" );
        add ( "id" , ({"box"}) );
	set_long(
	  "這是曾屬於黑龍的盒子，據說具有強大的力量，足以毀天滅地。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "個" );
	set( "weight", 10 );
	set( "value", ({ 1, "gold" }) );
}
