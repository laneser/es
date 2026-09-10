// 王藥師的茅屋外的小廣場
#include <mudlib.h>
#include "wang.h"
inherit ROOM;
inherit DOORS;

void create()
{
 	::create();
        set_short("空地");
	set_long(@C_LONG
這裡原本是雜草叢生的地方，不過已經被清出一片空地了。地上鋪了些
待曬乾的草藥, 空地的另一邊堆了一些柴, 還有一個竹籠。前方有個小茅屋。
C_LONG
);
	set("light", 1);
	set("exits",([
		"north" : WANG"room1",
		"south" : WANG"room3", 
		"enter" : WANG"room6",
	]));

	create_door("enter","out",([
		"keyword" : ({"iron door","door"}),
		"name" : "iron door",
		"c_name" : "鐵門",
		"c_desc" : "這是一扇厚重的鐵門, 門下有個很小的小開口",
		"status" : "locked",
		"lock"	: "WANG",
	]) );
		
	reset();
}


