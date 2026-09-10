#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
#include <compress_obj.h>
	set_name( "makira potion", "瑪吉拉藥水" );
	add( "id", ({ "potion", "makira" }) );
	set_short( "瑪吉拉藥水" );
	set_long(
		"這瓶藥水上面標示著: 「瑪吉拉」，旁邊註明: 緊急醫療用。\n"
	);
	set_healing( 90 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 30 );
	set( "value", ({ 500, "silver" }) );
	set( "medication", 70 );
	set( "effect_critical", 80 );
}
