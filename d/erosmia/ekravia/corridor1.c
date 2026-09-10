#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("走廊");
	set_long(
@CLong
這裡是旅店中的一角, 由這裡往北可以回到大廳。西邊則是一家熱鬧的
小酒吧。
CLong
);
	set("exits", ([
		"west"		: HERE"bar",
		"north"		: HERE"tavern",
		]));
}
