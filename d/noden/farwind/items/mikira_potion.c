#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "mikira potion", "米吉拉藥水" );
	add( "id", ({ "potion", "mikira" }) );
	set_short( "米吉拉藥水" );
	set_long(
		"這瓶藥水上面標示著: 「米吉拉」，旁邊註明: 醫療輕傷用。\n"
	);
	set_healing( 20 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 20 );
	set( "value", ({ 80, "silver" }) );
	set( "medication", 20 );
	set( "effect_critical", 100 );
}
