#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("the east gate", "東門");
	set_long(@Long
你看到一道低矮的圍牆, 與一道拱門。一條不寬不窄的道路由拱門下
穿過, 往東伸入廣闊的田野中。圍牆西邊是一個幽雅的城鎮, 那正是吟遊
詩人們常常歌詠的美麗故鄉「愛卡拉維亞」。
Long
);
	set("exits", ([
		"east"		: "/d/erosmia/11,10.erosmia",
		"west"		: HERE"tinker_way1",
		]));
}
