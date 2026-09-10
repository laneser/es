// wenro2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("峽谷的底部");
    set_long(@C_LONG
你來到了一個峽谷的底部，橫在你面前的是一條清徹的河流，映著兩岸高
聳峭壁的倒影，你不由得由心中讚歎起這美麗的造物主傑作。你身後的巖壁上
掛滿了慵懶地垂著的藤蔓，藤蔓的後面似乎有個小洞。
C_LONG
    );
    reset();
}

void init()
{
    add_action("to_enter", "enter");
}

int to_enter(string s)
{
    if (!s || s != "hole")
	return notify_fail("你想進入哪裡?\n");
    else
    {
	write("你穿過巖壁後的小洞，來到一個新的地方 ...\n");
	this_player()->move(AREA"wenro3");
    }

    return 1;
}
