#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小徑");
	set_long(@Long
工匠小徑往東西方向延伸, 西邊不遠處就是城鎮的西門了。小徑往西
爬上山丘, 通往著名的寶石礦坑。
路上人跡不多, 兩旁的房屋大多低矮而樸素, 不過越往東側房屋越高大。
從這裡往東走一段路就可以抵達鎮上最繁華的中心廣場。
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way4",
		"west"		: HERE"west_gate",
		]));
}
