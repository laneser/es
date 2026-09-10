// lib6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．長廊");
    set_long(@C_LONG
你現在身處於一條長長的走廊上，大理石鋪成的走道向西方延伸。東邊牆  
壁上有個小銅環，似乎是某種開關 (switch) 。長廊的牆壁不知是用什麼東西
所建造的，閃耀著淡淡的光芒。
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib5",
	]) );
    set("item_desc", ([
	"wall" : "牆上畫著一串好像是烤肉的東西 .... 嗯 :D~~~~\n",
	"switch" : "這個銅環好像可以拉 (pull) 的樣子 ....\n"
	]) );
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_pull", "pull");
    add_action("to_search", "search");
}

int to_pull(string s)
{
    object p;
    p = this_player();

    if (s == "switch")
    {
	tell_object(p, @NOTHING
你小心地拉動銅環，但是似乎什麼事情都沒有發生 .....
..............

地板好像又不見了的樣子 .....
..............

哇～～～

NOTHING
	);
	p->move(AREA"lib7");
        tell_room(environment(p), "你聽見一聲慘叫，但是你左看右看，都看不到有什麼事發生 ....\n", ({p}));
        return 1;
    }
    else
	return notify_fail("你想拉什麼?\n");
}

int to_search(string s)
{
    object p;
    p = this_player();

    if (s == "south")
    {
	tell_object(p, @OK
當你盯著南邊牆上畫的烤肉串流口水的時候，忽然發現牆角有個按鈕，於是
你順手一按 .... 

你的眼前突然強光一閃，當你恢復視覺時，你發現四周的景物已經變了 ....

OK
	);
	p->move(AREA"lib8");
	return 1;
    }
    else return notify_fail("你想找什麼? 這裡有什麼有趣的東西嗎?\n");
}

