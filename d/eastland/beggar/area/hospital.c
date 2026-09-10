#include "../dony.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("藥鋪");
	set_long( @C_LONG
你一走進這家藥鋪就聞到一股藥草味。 這裡是『薪膽村』唯一的一家可以醫
療的藥鋪 ,主人小雪子精通醫術,而這裡所賣的東西也不貴, 所有的東西則全寫在
一張掛在壁上的畫軸(paper)上。你可以看看它並且買你所需要的。
C_LONG
	);
	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"up":DBEGGAR"hospital1.c",
		"east":DBEGGAR"north1.c"
		       ]) );
	
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
		({ "/d/noden/farwind/items/white_plaster", 40, 30 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 30, 30 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 40 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 20 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}
