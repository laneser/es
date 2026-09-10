#include "forest.h"

inherit ROOM;

void create()
{
	::create();
	set_outside("noden");
	set_short("黑森林");
	set_long(@CLong
你站在黑森林的入口。如它的名字一般, 這個森林的樹木異常地茂密
, 使得無論多麼強烈的陽光都完全無法穿透進來。據傳說, 這是受到魔族
邪惡魔法的影響, 森林中的一草一木、小動物們都變成邪惡的黑暗生物。
    此外, 許多傳言指出此地有著前往魔族古帝國的秘密通道。
CLong
);
	set("exits",([
		"north" : HERE"1n",
		"south" : "/d/noden/8,14.noden",
	]));
	set("no_monster", 1);
	set("exit_suppress", ({ "north", }) );
  	reset();

}
