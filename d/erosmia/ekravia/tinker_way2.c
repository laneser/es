#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小徑");
	set_long(@Long
你走在工匠小徑上, 北邊有一間造型奇特的魔法屋。裡面不知在販賣
著什麼奇怪的物品。
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way1",
		"west"		: HERE"tinker_way3",
		"north"		: HERE"magic_shop",
		]));
}
