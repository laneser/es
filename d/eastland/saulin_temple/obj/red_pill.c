#include <mudlib.h>

inherit PILL;

void create()
{
	pill::create();
	set_name( "shou-lin pill", "玉靈散" );
	add( "id", ({ "pill" }) );
	set_short( "玉靈散" );
	set_long(
		"玉靈散乃少林內服治傷良藥\n" 
	);
	set_healing( 40 );
	set( "no_sale", 1 );
	set( "weight", 5 );
	set( "value", ({ 10, "gold" }) );
	set( "medication", 35 );
	set( "effect_critical", 75 );
}
