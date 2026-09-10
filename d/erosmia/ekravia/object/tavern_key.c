#include "../ekravia.h"
inherit OBJECT;

void	create()
{
//	::create();
	set_name("small copper key");
	set_short("銅製小鑰匙");
	set_long("這是一把銅做的小鑰匙, 鑰匙柄上刻著迪諾旅店的標記。\n");
	add( "id", ({"key", "copper key"}) );
	set( "weight", 0);
	set( "unit", "把");
	set( "value", 0);
}

