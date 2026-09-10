#include "../../story.h"

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("藥店");
	set_long( @C_LONG
你一走進這家藥店就聞到一股刺鼻的藥草味。這裡是「巫咸城」裡唯一的一家
合法藥店，專門做些藥物買賣交易的工作。這裡所賣的東西不貴，也沒有人會去討
價還價的，所有的東西則全寫在一張掛在壁上的單子(menu)，你可以看看它並且買
所需要的東西。
C_LONG
	);
	set( "item_func", ([
		"menu" : "show_menu"
	]) );
	set( "light", 1 );
	set( "exits", ([
		"west":SCITY"ws"
		       ]) );
	
	set( "objects", ([
	       "doctor":SWMOB"wiz_doctor1",
            "patient#1":SWMOB"patient1", 
            "patient#2":SWMOB"patient1",
            "patient#3":SWMOB"patient1",
	]) );
	set_inventory( ({
		({ "/obj/bandage",60,20 }),
		({ "/d/noden/farwind/items/white_plaster", 40, 20 }),
		({ "/d/eastland/easta/obj/spicy_plaster", 30, 20 }),
		({ "/d/eastland/easta/obj/green_pill", 40, 30 }),
		({ "/d/eastland/easta/obj/small_pill", 30, 20 }),
		({ "/d/eastland/easta/obj/large_pill", 20, 15 }),
	}) );
	reset();
}
void reset()
{
	room::reset();
	seller::reset();
}
