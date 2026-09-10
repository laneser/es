#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "kira potion", "吉拉藥水" );
	add( "id", ({ "potion", "kira" }) );
	set_short( "吉拉藥水" );
	set_long(
		"這瓶藥水上面標示著: 「吉拉」，旁邊註明: 服用drink。\n"
	);
	set_healing( 50 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 25 );
	set( "value", ({ 250, "silver" }) );
    set( "medication", 40 );
    set( "effect_critical", 90 );
}
