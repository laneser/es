#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	base_room::create();
	set_light(1);
	set_short("楓林酒吧");
	set_long(@CLong
你走進一家酒吧。圓桌、高腳椅、酒杯、高談闊論的人與空氣中的酒
精味道一同混雜於這個不大的空間。酒保 (barkeeper) 與他的吧檯 (bar)
隱藏在房間的一角, 幾個顧客坐在前面。
CLong
);

	set("c_item_desc", ([
		"bar"		: @ITEM_BAR
你走近吧檯, 發現上面放了一本菜單 (Menu)。 
ITEM_BAR
		, "menu"	: @ITEM_MENU
這是一本普通的菜單, 你可以仔細讀讀 (read) 它。
ITEM_MENU
	]) );

	set("exits", ([
		"east"		: HERE"corridor1",
	]));
	
	set( "objects", ([
		"barkeeper" :	MOB"barkeeper",
	]) );
	
	set_inventory( ({
		({ OBJ"potions/rum", 20, 20 }),
	}) );
	reset();
}

void	init()
{
	seller::init();
	base_room::init();
	add_action( "read_menu", "read" );
}

int	read_menu(string s)
{
	if (!s) return 0;
	if (s = lower_case(s) != "menu")	return 0;
	write ( @MENU_MSG
你翻開菜單細讀, 上面寫著
MENU_MSG
	);
	show_menu();
	
	return 1;
}