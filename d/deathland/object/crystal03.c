#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "green crystal", "綠色魔水晶" );
	add( "id", ({ "crystal" }) );
	set_short( "green mystic crystal", "綠色魔水晶" );
	set_long(
	    "The green mystic crystal shinning terrible lights.\n",
	    "閃耀著邪惡綠色光芒的神秘的水晶石.\n"
	);
	set( "no_sale", 1 );
	set( "unit", "個" );
	set( "echo_crystal",3);
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
}
