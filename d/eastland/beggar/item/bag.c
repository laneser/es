#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_c_open_long("這個乾坤一氣袋可以用來裝一些小東西。\n");
	set_name("bag", "乾坤一氣袋");
	set_short("乾坤一氣袋");
	set( "weight", 20);
	set( "weight_apply", 50 );
   set( "max_load", 230 );
	set( "value", ({ 150, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}
