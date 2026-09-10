// lib8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．秘室");
    set_long(@C_LONG
這是一個空空湯湯的房間，房間的中央飄浮著一顆閃亮的紅水晶。你仔細
一瞧，水晶上還畫著奇怪的圖案。東邊的牆上刻著一些碑文 (runes)，北邊是
一個魔法力場，似乎可以通過的樣子。
C_LONG
    );
    set("exits", (["north" : AREA"lib6"]));
    set("item_desc", ([
	"runes" : @RUNE
可敬的勇士：

    紅水晶上的圖案就是傳說中的納突尼之印，你可以把它描繪 (sketch) 下
來帶在你的身上，就可以獲得封印之門的認可，穿過封印之門到達被封印的地
方去。

    願吾神女王榮光常伴左右。

					希達．尼普頓
RUNE
	]) );
    
    set("light", 1);
    reset();
}

void init()
{
    add_action("to_sketch", "sketch");
}

int to_sketch()
{
    object p;
    p = this_player();
    
    if (p->query(QUESTNAME) >= 1)
    {
	return notify_fail("你已經畫過一次了，就省省力氣吧。\n");
    }

    p->set(QUESTNAME, 1);
    tell_object(p, "你小心翼翼地把納突尼之印描繪在魔法字典的筆記欄裡。\n");
    write("[你完成了 失落的封印 第一階段的任務，獲得 5000 點經驗]\n");
    this_player()->finish_quest(QUESTNAME, 1);
    this_player()->gain_experience(5000);
    return 1;
}

