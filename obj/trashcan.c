// A trashcan
// By Annihilator@Eastern.Stories

#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "trashcan", "垃圾桶" );
	set_short( "垃圾桶" );
	set_c_open_long( "一個造型新潮的垃圾桶，上面寫著「資源回收，大家一起來」。\n"
		"你可以用 toss 指令將不用的物品丟進垃圾桶。\n" );
	set( "prevent_get", 1 );
	set( "max_load", 200000 );
}

void init()
{
	add_action( "do_toss", "toss" );
}

int do_toss(string arg)
{
	object dest;

	if( !arg || !(dest = present(arg, this_player())) )
		return notify_fail("你要把什麼東西丟進垃圾桶？\n");
	if( dest->query("prevent_drop") || dest->query("secure") )
		return notify_fail("你不能丟掉這樣東西。\n");
	write("你將" + dest->query("short") + "丟進垃圾桶。\n");
	tell_room( environment(), 
		this_player()->query("c_name") + "把" + dest->query("short") + "丟進垃圾桶。\n",
		this_player() );
	call_out( "reward", 5 );
	dest->remove();
	return 1;
}

void reward()
{
	object coin;
	tell_room( environment(), 
		"你聽到垃圾桶裡傳來一陣可怕的笑聲。\n" );
	coin = new("/std/coins");
	coin->set_type( "silver" );
	coin->set_number(1);
	coin->move( environment() );
}
