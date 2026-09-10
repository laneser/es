#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "large pill", "大還丹" );
	add( "id", ({ "pill" }) );
	set_short( "大還丹" );
	set_long(@C_LONG
這是一粒用千年人參、雪蓮等藥材煉製成的大還丹，服用(eat)後可以
恢復大量體力。
C_LONG
	);
	set_healing( 100 );
	set( "no_sale", 1 );
        set( "weight", 30);
	set( "value", ({ 100, "gold" }) );
	set( "medication", 85 );
	set( "effect_critical", 50 );
}
