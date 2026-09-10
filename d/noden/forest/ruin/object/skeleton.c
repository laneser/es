#include "../ruin.h"

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name("a pile of bones", "一堆枯骨");
	set_short("散落在地面上的一堆枯骨");
	set_long(
	   "這堆枯骨, 看來似乎是人的骨骸, 散在這裡不知已經過了多少的歲月。\n");
	set("id", ({ "bones", "skeleton"}));
	set("unit", "堆");
	set("weight", 50 );
	set("use_less", 1);
	set("value", ({ 0, "silver" }) );
	set("prevent_get", 1);
	set("prevent_get_c_msg","讓它安息吧! 別打攪死者。\n");
	set("prevent_insert", 1);
	set("prevent_drop", 1);
}

void	init()
{
	add_action( "do_search", "search" );
}

int		do_search(string s)
{
	if (!s)	return 0;
    if ( s == "skeleton" || s == "bones" )
	{
		printf( "%s", "當你試著翻開骨骸時, 它突然快速地風化為一堆"
		"細沙, 散失於風中。\n");
		this_object()->remove();
		return 1;
	}
}
