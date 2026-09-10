#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("a small road","小路");
	set_long(@CLong
你站在一條泥土小路上, 小路兩旁種滿了好些不知名的果樹。幾間農
家隱藏在樹蔭下, 偶而飄出幾許炊煙。
CLong
);
	set("exits", ([
		"east"		: HERE"maple_street1",
		"west"		: HERE"small_road2"
		]));
}
