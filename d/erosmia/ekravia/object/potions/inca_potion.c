#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "inca potion", "印卡藥水" );
	add( "id", ({ "potion", "inca" }) );
	set_short( "印卡藥水" );
	set_long( @LONG
這是由愛卡拉維亞附近特產的一種昆蟲, 與一些其他的藥材經魔法調配而
成的藥水, 具有少許的醫療能力。
LONG
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 20 );
	set( "value", ({ 100, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
