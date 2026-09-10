#include <mudlib.h>
#include "wang.h"
inherit ROOM;

void create()
{
 	::create();
        set_short("花圃");
	set_long(@LONG
走到這裡，讓你眼前一亮。這裡開滿了各種花，放眼望去，一片花海。陣陣花香，
讓你覺得彷佛身在仙境。紅的、黃的、白的、藍的、紫的甚至稀有的黑色的花，這裡
都可以看到。水桶，小鏟子，鋤頭等等工具四處散著，顯然這裡的花是有人細心照顧
的。
LONG
);
	set("light", 1);
	set("exits",([
		"west" : WANG"room1" 
	]));

	reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string arg)
{
    object o;

    write("你找了半天，除了花之外還是花 ....\n");
    o = new("/d/healer/plant/opium_poppy_plant");
    o->move(this_object());
    return 1;
}

