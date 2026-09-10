#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	::create();
	set_light(1);
	set_short("小藥店");
	set_long(@Long
你走進一家小藥店。昏暗的小空間裡, 各種藥材的氣味在空中飄湯著
。一個個盛著不知名藥物的小瓶子互相推擠著塞滿了整個櫃檯, 幾個空燒
杯與酒精燈在小桌上的一角建立了自己的勢力範圍。
    好不容易你在櫃檯的一角, 幾個藥瓶的空隙間找到了你所需要的藥品
清單 (list)。
Long
);

	set("item_func", ([
		"list"		: "show_menu",
		]) );

	set("exits", ([
		"north"		: HERE"tinker_way3",
		]) );
	set("objects", ([
		"alchemist"	: MOB"alchemist",
		]) );
	set_inventory( ({ 
		({ OBJ"potions/inca_potion", 50, 50 }),
		({ OBJ"potions/green_potion", 30, 30 }),
		({ OBJ"potions/vigor_potion", 30, 30 }),
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
