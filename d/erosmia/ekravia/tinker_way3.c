#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("工匠小徑");
	set_long(@Long
工匠小徑沿著東西方向延伸。西邊不遠處就是鎮上的中心廣場, 南邊
有一家小藥屋。從這裡往東一段距離可以看到東門, 從東門出去則是一片
廣闊的原野。
Long
);
	set("exits", ([
		"south"		: HERE"potion_shop",
		"east"		: HERE"tinker_way2",
		"west"		: HERE"square",
		]));
}
