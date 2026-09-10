#include "../island.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("老桐閣藥鋪分號");
	set_long( @C_LONG_DESCRIPTION
你一走進這家藥鋪，就聞到一股濃郁的檀香，這是由若嵐城歷史最老
的老桐閣藥鋪在此所開的分號。從尋常的刀傷藥膏，到難得一見的千年老
參，這裡都有，這家藥鋪還有一種祖傳的刀傷藥配方叫做「天香斷續膏」
，治外傷靈驗無比，這裡所賣的藥材與價錢都寫在一張掛在壁上的卷軸
(paper)上。
C_LONG_DESCRIPTION
	);

	set( "item_func", ([
		"paper" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"east" : ITOWN"town06" ]) );
	set_inventory( ({
		({ "/obj/bandage",60,60 }),
		({ "/d/eastland/easta/obj/plaster", 40, 40 }),
		({ "/d/eastland/easta/obj/white_plaster", 30, 30 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 20, 20 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 40 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 30 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 20 }),
		({ IOBJ"paste",20,20 }),
	}) );
	reset();
}
void reset()
{
      seller::reset();
      room::reset();
      return;
}
