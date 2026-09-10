#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "騎士商店");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你現在來到了騎士公會內部所附設的商店，這裡賣的東西雖然不是頂好，不
過對於剛來到這個世界的騎士而言，一些基本裝備總是有所幫助的，你可以翻閱
桌上的價目表(menu)，看看這裡賣些什麼。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/knight/fortress/knight_inner" ]) );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set_inventory( ({
		({ "/d/knight/fortress/weapons/battleaxe", 3, 3 }),
		({ "/d/knight/fortress/weapons/waraxe", 5, 5 }),
		({ "/d/knight/fortress/weapons/longsword", 10, 10 }),
		({ "/d/knight/fortress/weapons/shortsword", 15, 15 }),
		({ "/d/knight/fortress/armors/chainmail", 10, 10 }),
		({ "/d/knight/fortress/armors/shield", 10, 10 }),
	}) );
	reset();
}

void reset()
{
	room::reset();
	seller::reset();
}
