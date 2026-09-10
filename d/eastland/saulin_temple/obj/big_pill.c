#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "large herb pill", "大塊靈芝" );
	add( "id", ({ "pill" }) );
	set_short( "大塊靈芝" );
	set_long(
		"這是一大塊成形靈芝的精華，服用(eat)後可以恢復不少體力。\n"
	);
	set_healing( 50 );
	set( "no_sale", 1 );
	set( "weight", 20 );
	set( "value", ({ 8, "gold" }) );
	set( "unit", "塊" );
	set( "medication", 40 );
	set( "effect_critical", 70 );
}
