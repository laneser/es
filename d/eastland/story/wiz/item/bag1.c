#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_c_open_long("無底袋是「巫咸國」的特產之一，可以裝無數的東西。\n");
	set_name("bag", "無底袋");
	set_short("無底袋");
	set( "weight", 20);
 	set( "weight_apply", 50 );
        set( "max_load", 230 );
	set( "value", ({ 150, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}
