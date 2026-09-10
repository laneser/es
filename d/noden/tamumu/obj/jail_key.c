#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "jail key", "監獄鑰匙" );
	add( "id", ({ "key" }) );
	set_short( "監獄鑰匙" );
	set_long(
		"這是塔姆姆監獄的鑰匙，上面沾滿了血跡。\n"
	);
	set( "to_lock", "TAMUMU_JAIL1" );
	set( "weight", 3 );
	set( "value", ({ 15, "silver" }) );
	set( "no_sale", 1 );
}
