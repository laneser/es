#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("the south gate", "南門");
	set_long(@Long
Long
,@CLong
你正站在一個美麗城鎮的入口處。在古樸的土牆背後, 你隱隱約約地
望見不遠處一棟棟磚紅色的洋房。道路穿過大門延伸進去, 但已不再是田
野間的泥土小路, 而是一塵不染的石板大道。
CLong
);
	set("exits", ([
		"south"		: "/d/erosmia/10,11.erosmia",
		"north"		: HERE"maple_street1",
		]));
}
