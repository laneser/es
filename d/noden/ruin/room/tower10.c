// tower10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔術師塔．第一層");
    set_long(@C_LONG
你現在在魔術師塔的第一層，這裡的地板並不像塔裡其他的地方一    
般畫滿了咒文，反而一平如鏡什麼東西都沒有。地板中央飄浮著一顆發
光的紫水晶，水晶的上頭似乎有些奇怪的圖案。
C_LONG
    );
    set("exits", ([
	"up" : AREA"tower1"
	]) );
    set("light", 1);
    set("item_desc", ([
	"ladder" : "一個向下的梯子。\n"
	]) );
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
    add_action("to_climb", "climb");
    add_action("to_search", "search");
}

int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 7)
    {
        return notify_fail("你已經畫過一次了，就省省力氣吧。\n");
    }

    p->set(QUESTNAME, 7);
    tell_object(p, "你小心翼翼地把莉莉雅之印描繪在魔法字典的筆記欄裡。\n");
    return 1;
}

int to_search()
{
    write("你發現牆角有個梯子 (ladder)。\n");
    return 1;
}

int to_climb(string arg)
{
    if (arg == "ladder")
    {
        write("你躡手躡腳地爬下梯子 ...\n");
        this_player()->move(AREA"tower8");
        return 1;
    }
    else
        return notify_fail("你想幹什麼?\n");
}
