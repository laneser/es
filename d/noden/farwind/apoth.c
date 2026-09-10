//#pragma save_binary

//translation done. 2-21-94 what about menu? hmm..  -Elon

#include <mudlib.h>
inherit SELLER;
inherit ROOM;

void create()
{
	::create();
    set_short("吉拉藥材店");
	set_long( @LONG_DESCRIPTION
你現在來到一家新開的藥材店，整齊的櫃檯上排放著許多醫療的用品，繃帶
、藥水、應有盡有，你看到門口的櫃檯上釘著一張價目表(menu)，你有預感這家
藥材店會是你常常光顧的地方。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/noden/farwind/wbazz" ]) );
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	set_inventory( ({
		({ "/obj/bandage", 60, 60 }),
		({ "/d/noden/farwind/items/branz_herb", 50, 50 }),
		({ "/d/noden/farwind/items/plaster", 40, 40 }),
		({ "/d/noden/farwind/items/white_plaster", 30, 30 }),
		({ "/d/noden/farwind/items/mikira_potion", 30, 30 }),
		({ "/d/noden/farwind/items/kira_potion", 30, 30 }),
		({ "/d/noden/farwind/items/makira_potion", 20, 20 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}
