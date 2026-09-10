#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "living pill", "續命藥丸" );
	set_short( "續命藥丸" );
        add ( "id" , ({"pill"}) );
	set_long(
	  "這是一顆續命藥丸，是用千種奇珍藥材煉成，據說可起死回生。\n"
	);
	set( "no_sale", 1 );
	set( "unit", "顆" );
	set( "weight", 2 );
	set( "value", ({ 1, "gold" }) );
}
