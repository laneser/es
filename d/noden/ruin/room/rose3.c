// rose3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("羅斯托麗城．城門");
    set_long(@C_LONG
你正站在一個懸崖的頂端，對岸是羅斯托麗城的城門。和前面斷垣殘壁的
景像截然不同，這個城門氣派宏偉無比，不禁令人神往古魔族帝國的輝煌。不
過麻煩的是，要如何渡過這個懸崖到對岸呢？
C_LONG
    );
    set("exits", (["south" : AREA"rose2"]) );

    reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_read", "read");
    add_action("do_jump", "jump");
    add_action("do_answer", "answer");
}

int do_search()
{
    tell_object(this_player(), "你發現腳下踩著一塊石碑，上面寫著一些文字。\n");
    return 1;
}

int do_read(string str)
{
    object p;
    p = this_player();

    if (str == "rune" || str == "runes")
    {
	if (p->query_temp("lilia_dic") == 1)
	    tell_object(p, "石碑上寫著：「回答密語，女王榮光常伴」\n");
	else
	    return notify_fail("你看了半天，還是不知道上面寫些什麼。\n");
    }
    else
	return notify_fail("你想讀什麼?\n");
    return 1;
}

int do_jump(string str)
{
    object p;
    p = this_player();

    if (!str || str != "down")
	return notify_fail("你想幹什麼? 想往下跳的話想清楚再跳哦 ...\n");
    else
    {
	tell_object(p, "你奮力向前一躍 ....\n\n");
	tell_room(environment(p), sprintf("%s很衝動地向懸崖底跳了下去 ....\n", p->query("c_name")), ({p}));
	tell_object(p, "你被水流衝到一個新的地方 ....\n\n");
	p->move("/d/noden/11,6.noden");
    }

    return 1;
}

int do_answer(string str)
{
    object p;
    p = this_player();
	
    if (str == "芝麻開門" || str == "open sesame")
    {
	if (p->query_temp("lilia_dic") != 1)
	    return notify_fail("你突然想起你還沒拿字典，進城去也沒用，於是就硬生生地把說到一半的話吞了回去。\n");
	p->set_explore("noden#47");
	tell_object(p, "忽然一陣白色的光芒籠罩在你四周，當光散去時，你發現四周的景物已經變了!\n");
	p->move_player(AREA"rose4", ({"%s被一道白光傳送走了!\n", "%s伴隨著一道光芒出現在這裡。\n"}), "");
    }
    else
	return notify_fail("女王的聲音從四面八方傳來：「不懂密碼就不要來吵我 ok?」\n");
    return 1;
}

