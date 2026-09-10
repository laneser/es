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
這裡是楓樹大街, 周圍相當地清靜。
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street1",
		"north"		: HERE"maple_street3",
		]));
}
