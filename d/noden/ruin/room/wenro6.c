// wenro6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("奇異的空間");
    set_long(@C_LONG
你現在一片虛無之中，只有一顆發著動人光芒的透明水晶陪著你。
水晶的上頭似乎有些奇怪的圖案。
C_LONG
    );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_search", "search");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 6)
    {
        return notify_fail("你已經畫過一次了，就省省力氣吧。\n");
    }

    p->set(QUESTNAME, 6);
    tell_object(p, "你小心翼翼地把希特斯之印描繪在魔法字典的筆記欄裡。\n");
    return 1;
}

int to_search()
{
    write("你四處不停地尋找，到底想找些什麼呢?\n");
    this_player()->move(AREA"rose4");
    return 1;
}
