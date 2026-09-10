// tower8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔術師塔．第二層");
    set_long(@C_LONG
這裡是魔術師塔的第二層，地板上畫滿了密密麻麻的奇特咒文，似乎是用
來禁制某種可怕的生物用的。空氣中充滿了腐屍的氣味，你的直覺告訴你如果
不快點設法離開這個地方，恐怕不久之後你也會變成一具屍體了。
C_LONG
	    );
    switch(random(3))
    {
	case 0: set("exits", ([
		    "east" : AREA"tower9",
		    "south" : AREA"tower7"
		    ]));
		break;
	case 1: set("exits", ([
                    "west" : AREA"tower9",
                    "south" : AREA"tower7"
                    ]));
                break;
	case 2: set("exits", ([
                    "north" : AREA"tower9",
                    "south" : AREA"tower7"
                    ]));
                break;
    }
    set("item_desc", (["ladder" : "一個通向上一層的梯子。\n"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_climb", "climb");
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
	write("你躡手躡腳地爬上梯子 ...\n");
        this_player()->move(AREA"tower10");
        return 1;
    }
    else
	return notify_fail("你想幹什麼?\n");
}

