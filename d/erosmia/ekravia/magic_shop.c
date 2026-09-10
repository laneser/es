#include "ekravia.h"
inherit SELLER;
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("魔法屋");
	set_long(@Long
這是一間充滿神秘氣氛的小屋, 一片陰暗中僅有櫃檯前的一角偶而漏
進一點陽光。櫃檯後面似乎沒人看著, 讓人有點不知所措。還好櫃檯上面
放著一張清單 (list)。
Long
);

	set("item_func", ([
		"list"		: "show_menu",
		]) );

	set("exits", ([
		"south"		: HERE"tinker_way2",
		]) );
	set_inventory( ({ 
		({ "/d/noden/moyada/obj/wands/flamming_wand", 5, 5 }),
		({ OBJ"firework", 5, 5 }),
		({ OBJ"chain_fw", 2, 1 }),
		}) );
	reset();		                                                                        
}

void	show_menu()
{
	write( @LIST
你看到一張泛黃的紙張, 上面寫著:
LIST
	);
	::show_menu();
}
