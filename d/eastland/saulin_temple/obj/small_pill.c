#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "herb pill", "小塊靈芝" );
	add( "id", ({ "pill" }) );
	set_short( "小塊靈芝" );
	set_long(
		"這是一塊成形靈芝的精華，服用(eat)後可以恢復一些體力。\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "weight", 10 );
	set( "value", ({ 5, "gold" }) );
	set( "unit", "塊" );
	set( "medication", 20 );
	set( "effect_critical", 80 );
}
