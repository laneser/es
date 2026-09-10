#include "forest.h"
inherit ROOM;

void create()
{
	::create();
	set_short("黑森林");
	set_long(@CLong
你走在陰森的黑森林中, 一股無法忽視的邪惡氣息讓你的神經異常地
緊繃。在這裡到處都可能充滿著危險, 注意你的四周! 小心不要成了黑暗
生物們的點心。
CLong
);
	set("exits",([
			"east"	: HERE"3n1w",
			"south"	: HERE"2n2w",
    ]));
    set("objects", ([ "ammunt" : MOB"ammunt", ]) );
    set("exit_suppress", ({ "south", }) );
	reset();

}
