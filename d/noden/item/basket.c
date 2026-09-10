#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "basket", "竹籃" );
   set_short( "竹籃" );
	set_c_open_long( "這是一個能裝東西的竹籃，雖然編得頗為粗糙，但是看起來相當耐用。\n" );
	set("prevent_put_money",1);
	set( "weight", 20 );
	set( "max_load", 140 );
	set( "value", ({ 13, "silver" }) );
}
