// tower3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔術師塔．第一層");
    set_long(@C_LONG
這裡是魔術師塔的第一層，地板上畫滿了密密麻麻的奇特咒文，似乎是用
來禁制某種可怕的生物用的。空氣中充滿了腐屍的氣味，你的直覺告訴你如果
不快點設法離開這個地方，恐怕不久之後你也會變成一具屍體了。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"tower2",
	"east" : AREA"tower2",
	"south" : AREA"tower2",
	"west" : AREA"tower2"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int to_search(string arg)
{
    write("你發現地上有塊磚頭似乎是某種秘門的按鈕 (button)。\n");
    return 1;
}

int recover(object p)
{
    p->set_temp("block_command", 0);
    tell_object(p, "這團迷霧慢慢地散去 .... 你發現四周的景物已經變了 ....\n");
    p->move(AREA"tower4");
    return 1;
}

int to_push(string arg)
{
    if (arg == "button")
    {
	write("一道黑霧迅速地籠罩在你的四周 ...\n");
        this_player()->set_temp("block_command", 1);
        call_out("recover", 15, this_player());
	return 1;
    }
    else
	return notify_fail("你想按什麼?\n");
}

