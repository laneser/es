#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("basket", "菜籃");
	set_short("菜籃");
	set_c_open_long("這是一個買菜用的籃子，可以裝東西。\n");
	set("weight", 50);
	set("weight_apply", 80 );
	set("max_load", 150);
	set("value", ({ 40, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
