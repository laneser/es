// entrance 4

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("地下水道");
    set_long(@C_LONG
這裡是一個似乎已經廢棄很久的輸水道，空氣中飄浮著一股令人不適的味
道。但是奇怪的是，這麼潮溼的地方連一隻蟑螂都沒有。你的面前有一條湍急
的小溪，西邊的牆上畫著一堆奇怪的符號，上面還有根扳杆 (lever)。
C_LONG
    );
    set("item_desc", ([
        "lever" : "這根扳杆不知道是什麼開關，你或許可以拉 (pull) 它。\n",
        "wall" : "這牆上畫著一堆奇怪的符號，或許是某種文字也說不定。\n"
        ]) );
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_swim", "swim");
    add_action("to_search", "search");
}

int to_pull(string str)
{
    object p;
    p = this_player();

    if (str == "lever")
    {
	tell_object(p, "你拉了一下扳杆，但是它馬上又彈回原來的位置，似乎什麼事情都沒有發生。\n");
	p->set_temp("lilia_0", 4);
	return 1;
    }
    else
	return notify_fail("你想拉什麼?\n");
}

int to_swim()
{
    object p;
    p = this_player();

    tell_object(p, "你正準備下水時，忽然腳下一個踩空 ... 哇～～～\n");
    tell_object(p, "\n你被水流衝到一個新的地方 ....\n\n");
    switch (p->query_temp("lilia_0"))
    {
	case 2:
	    p->move(AREA"en2");
	    break;
	case 4:
	    p->move(AREA"en7");
	    break;
    }
    return 1;
}

int to_search()
{
    string dir;
    switch (this_player()->query_temp("lilia_0"))
    {
        case 2: dir = "南";
                break;
        case 4: dir = "北";
                break;
    }
    write("除了流向"+dir+"方的水道外，什麼東西都沒有。\n");
    return 1;
}

