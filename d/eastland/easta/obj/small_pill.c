#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "small pill", "小還丹" );
	add( "id", ({ "pill" }) );
	set_short( "小還丹" );
	set_long(@C_LONG
這是一粒用人參、靈芝等藥材煉製成的小還丹，服用(eat)後可以
恢復一些體力。
C_LONG
	);
	set_healing( 60 );
	set( "no_sale", 1 );
        set( "weight", 20);
	set( "value", ({ 45, "gold" }) );
	set( "medication", 50 );
	set( "effect_critical", 60 );
}
