#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
#include <compress_obj.h>
	set_name( "green pill", "百草丹" );
	add( "id", ({ "pill" }) );
	set_short( "百草丹" );
	set_long(@C_LONG
這是一粒用上百種滋補藥材煉製成的百草丹，服用(eat)後可以
恢復不少體力。
C_LONG
	);
	set_healing( 30 );
	set( "no_sale", 1 );
        set( "weight", 10);
	set( "value", ({ 18, "gold" }) );
	set( "medication", 30 );
	set( "effect_critical", 65 );
}
