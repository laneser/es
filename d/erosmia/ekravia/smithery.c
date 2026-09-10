#include "ekravia.h"
inherit BASE_ROOM;
inherit SELLER;

void	create()
{
	::create();
	set_light(1);
	set_short("鐵匠鋪");
	set_long(@Long
你走進鐵匠鋪, 敲敲打打的聲音簡直是震耳欲聾。聲音的來源來自房
間一角的鐵砧。熱得不得了的鼓風爐在鐵砧旁不遠處。房間的其他地方散
亂放著一些工具。
    牆上掛著幾把武器, 大概都是這裡的產品。武器下方放著一些鎧甲,
鎧甲旁邊釘著一個木牌(sign)
Long
);

	set("item_func", ([
		"sign"		: "show_menu",
		]) );

	set("exits", ([
		"north"		: HERE"tinker_way4",
		]) );

	set_inventory( ({ 
		({ OBJ"longsword", 5, 5 }),
		({ OBJ"dagger", 3, 3 }),
		({ OBJ"chainmail", 5, 5 }),
		}) );
		
	set("objects", ([
		"smith"	: MOB"smith",
		]) );
	reset();		                                                                        
}

void	show_menu()
{
	write( @LIST
你看到一塊粗糙的木牌, 上面刻著:
LIST
	);
	::show_menu();
}
