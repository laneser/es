#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","楓樹大街");
	set_long(@Long
Long
,@CLong
你走在繁華的大街上, 兩旁開滿了各式各樣的商店。鎮上唯一的冒險
者雜貨店就開在大街西邊的一棟大洋房中。
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street3",
		"north"		: HERE"square",
		"west"		: HERE"shop"
		]));
}
