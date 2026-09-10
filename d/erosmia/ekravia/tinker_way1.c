#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小徑");
	set_long(@Long
這裡是工匠小徑, 東邊不遠處就是城鎮的東門了, 遠遠的可以望見門
外的廣闊的原野。由小徑往西可以到達鎮上的中心廣場, 那裡有著附近最
大的市集。
Long
);
	set("exits", ([
		"east"		: HERE"east_gate",
		"west"		: HERE"tinker_way2",
		]));
}
