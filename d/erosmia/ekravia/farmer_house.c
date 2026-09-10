#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("a farmer's house", "農家");
	set_long(@CLong
你走進一家農家, 看見門口的廣場上幾隻鴨子正悠哉悠哉地閒晃著。
一個老人坐在門口, 安詳地望著廣場外的景色。
CLong
);
	set("exits", ([
		"south"		: HERE"small_road2"
		]));
	set( "objects", ([
		"oldman": MOB"old_man",
		"duck1"	: MOB"duck",
		"duck2"	: MOB"duck",
	]) );
	reset();
}
