// g8.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("廢棄的花園");
    set_long(@C_LONG
你來到了一個廢棄的花園，到處長滿了雜草和青苔。這裡的空氣充滿著肅
殺的氣氛，似乎連你身上的血液也快要為之凝結起來。雜草中似乎隱藏著一個
什麼東西，但是你看不清楚。
C_LONG
	    );
    set("exits", ([
	"south" : AREA"g2"
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_sketch", "sketch");
}

int to_search()
{
    write("草叢裡有一顆閃閃發亮的綠色水晶，水晶的上頭有奇怪的圖案。\n");
    return 1;
}


int to_sketch()
{
    object p;
    p = this_player();

    if (p->query(QUESTNAME) > 5)
    {
        return notify_fail("你已經畫過一次了，就省省力氣吧。\n");
    }

    p->set(QUESTNAME, 5);
    tell_object(p, "你小心翼翼地把海地亞之印描繪在魔法字典的筆記欄裡。\n");
    return 1;
}

