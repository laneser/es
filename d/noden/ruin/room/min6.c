// min6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿內廳");
    set_long(@C_LONG
你現在在神殿的內廳裡，四周一片空空湯湯，只有素淨的牆壁和天
花板靜靜地立著。凜冽的寒風由四面八方吹來，令你覺得有些寒冷。「
哪來的這麼大風？」你的心中不由得納悶著。  
C_LONG
    );
    set("item_desc", ([
	"plate" : "一塊小小的木牌，上頭寫著：「風神力．氣盾之壁」\n",
	"button" : "紅黃藍三種顏色的按鈕。\n"
	]) );
	
    set("exits", ([
	"north" : AREA"min7",
	"south" : AREA"min5"
	]) );
    set("pre_exit_func", ([ "north" : "exits_open" ]) );

    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_push", "push");
}

int exits_open()
{
    if (this_player()->query_temp("lilia_pass") == 3)
    {
	write("你身體裡忽然湧現一股神奇的力量，你輕易地穿過氣盾牆。\n");
    	return 0;
    }
    else
    {
	write("一道無形的阻力擋住你的去向。\n");
	return 1;
    }
}

int to_search(string s)
{
    if (!s)
    {
	write("你找了又找，發現地上似乎有塊小木牌 (plate)。\n");
	return 1;
    }
    else if (s == "plate")
    {
	write("小木牌上面有三個按鈕 (button)。\n");
	return 1;
    }
    else if (s == "button")
    {
	write("這三個按鈕除了顏色不同，其他大小形狀都一樣。\n");
	return 1;
    }
    else
	return notify_fail("你想找什麼？這裡好像沒什麼東西嘛 ...\n");
}

int to_push(string s)
{
    string color;
    object p;
    int order;

    if (!s)
    {
	return notify_fail("你想按什麼？\n");
    }

    sscanf(s, "%s button", color);
    p = this_player();
    order = p->query_temp("lilia_pass");

    switch (color)
    {
	case "red": 
	    if (order == 4)
		p->set_temp("lilia_pass", 5);
	    else
		p->set_temp("lilia_pass", 2);
	    break;
	
	case "blue":
	    p->set_temp("lilia_pass", 4);
	    break;

	case "yellow":
	    if (order == 5)
		p->set_temp("lilia_pass", 3);
	    else
		p->set_temp("lilia_pass", 2);
	    break;
	default:
	    return notify_fail("你想按什麼顏色的按鈕?\n");
     }

     write("你按下按鈕，但是似乎什麼事都沒有發生 ...\n");
     return 1;
}
        
