#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("shadow bag", "幻影袋");
	add( "id", ({ "bag" }) );
	set_short("幻影袋");
	set_c_open_long("這是一個幻影袋 .當你打開它想要看清它的容量時 ,你發現裡面是一團漆黑,\n"
	                "深不見底.\n"
	                );
	set("weight", 15);
	set("weight_apply", 40 );
	set("max_load", 300);
	set("value", ({ 1500, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
