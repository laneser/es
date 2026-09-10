#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小徑");
	set_long(@Long
你走在工匠小徑上, 東邊不遠處就是這個城鎮的中心廣場。南邊的街
上開了一家鐵匠鋪, 從裡面不時有叮叮咚咚的敲打聲傳出來。
Long
);
	set("exits", ([
		"east"		: HERE"square",
		"west"		: HERE"tinker_way5",
		"south"		: HERE"smithery",
		]));
}
