#include <mudlib.h>
#include "wang.h"
inherit ROOM;
inherit DOORS;
create()
{
	::create();
	set_short("籠子");
	set_long(@C_LONG
這是一個陰暗的籠子, 地上到處都是血跡和一些殘缺的屍體,
空氣中濃濃的血腥味, 陰暗處似乎有雙眼睛瞪著你, 你不禁害怕起來。
C_LONG
	);
	set("exits",([
		"out" : WANG"room2",
	]));
        create_door("out","enter",([
                "keyword" : ({"iron door","door"}),
                "name" : "iron door",
                "c_name" : "鐵門",
                "c_desc" : "這是一扇厚重的鐵門, 門下有個很小的小開口",
                "status" : "locked",
		"lock"	: "WANG"
        ]) );
	reset();
}
