// lib0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．大廳");
    set_long(@C_LONG
走進正門後，映入你眼簾的是一個寬敞幽靜的大廳。地板是由黑的發亮的
石塊所鋪成，四周的牆壁和天花板上滿布著美麗的壁畫和精緻的石雕。在旁邊
有一座氣派的弧型樓梯通往二樓，樓梯的扶把上也襯著光彩奪目的精美雕飾。
大廳的正中央有個水池 (pool) 散發著神秘的光芒，你不禁想走近看看。
C_LONG
    );
    set("exits", ([
	"out" : AREA"rose4",
	"up" : AREA"lib9"
	]));
    set("light", 1);
    set("item_desc", ([
	"pool" : @POOL
水池的中央有一尊女神像 (statue) ，神像的底座上有個小銅牌 (plate)。水
池裡的水十分的清澈，周圍的護欄上有著幾個小洞。
POOL
,
	"statue" : @STATUE
這是一尊雕刻的栩栩如生的女神像，雖然她的容貌並不十分美麗，但是眉宇之
間隱隱透著一股威嚴。
STATUE
,
	"plate" : "銅牌上面寫著：「女王的微笑」□希達．尼普頓。\n"
,
	"tube" : "這些水管被扣環牢牢地釘在水底。\n"
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
    add_action("to_insert", "insert");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "pool")
	tell_object(p, "池底有幾根水管 (tube)，不知道是做什麼用的。\n");
    else if (s == "tube")
    {
	tell_object(p, "有根水管似乎可以左右搖掙搖掙，有些不同。\n");
	p->set_temp("lilia1", 1);
    }
    else if (s == "hole")
        if (p->query_temp("lilia1") == 1)
	    tell_object(p, "護欄上有個小洞，似乎正對著那根水管。\n");
	else if (p->query_temp("lilia1") == 2)
	    tell_object(p, "小洞的下方似乎有個按鈕，不細看還看不出來。\n");
	else
	    tell_object(p, "護欄上有些小洞，不知道是幹什麼用的。\n");
    else
	return notify_fail("你想找什麼？這裡這麼大可能要找到明年哦!\n");

    return 1;
}

int to_insert(string s)
{
    string src, dest;
    object p;
    p = this_player();

    if (!s)
	return notify_fail("Syntax: insert <obj1> into <obj2>\n");

    sscanf(s, "%s into %s", src, dest);
    if (src != "tube" || dest != "hole")
	return notify_fail("喂，控制一下，不要插錯洞了 ....\n");
	p->set_explore("noden#45");
    p->set_temp("lilia1", 2);
    tell_object(p, "你把水管插進了洞裡，但是它立刻又彈了回來。\n");
    return 1;
}

int to_push(string s)
{
    object p;
    p = this_player();

    if (s != "button" || p->query_temp("lilia1") != 2)
	return notify_fail("你想按什麼?\n");

    tell_object(p, @PUSH
當你按下按鈕時，你發現神像正對著你微笑，令你魂搖神馳。當你回過神來的
時候，你發現周遭的景物已經變了。

PUSH
		);
    p->move_player(AREA"lib1", "SNEAK", "");
    return 1;
}

