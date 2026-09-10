// abyss3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("深淵");
    set_long(@C_LONG
你現在處於一個深淵的底部，四周圍繞著一片灰濛濛的霧氣。雖然是在濃
霧之中，但是你隱約覺得有許多眼睛正在窺伺著你，彷佛像地獄中探頭出來的
惡靈一般地鬼鬼祟祟。在這片黑暗之中，找到光明似乎正是你的當務之急。
C_LONG
    );
    set("item_desc", ([
	"candle" : "一根慘白的白色蠟燭，點亮它或許可以得到光明。\n"
	]) );
    set("exits", ([
	"northeast" : AREA"abyss5",
	"southeast" : AREA"abyss6",
	"south" : AREA"abyss1"
	]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_light", "light");
}

int to_search()
{
    write("你找了又找，發現地上插著根蠟燭 (candle)。\n");
    return 1;
}

int to_light(string s)
{
    object p;
    int count;

    if (s != "candle")
	return notify_fail("你想點亮什麼？\n");

    p = this_player();
    tell_object(p, "你點亮了蠟燭 ... 但是它卻自動熄滅了 ...\n");

    if (p->query_temp("lilia_abyss"))
    	count = p->query_temp("lilia_abyss");
    else
	count = 0;

    if (count < 4)
        count++;

    p->set_temp("lilia_abyss", count);
    return 1;
} 
