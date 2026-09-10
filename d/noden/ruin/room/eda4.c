// eda4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依達波第亞宮．覲見室");
    set_long(@C_LONG
這座宮殿雖然已經毀壞了，但覲見室裡的王座 (throne) 卻依然是完好如
初，一樣地金碧輝煌。在你的左右方各有一道小門，應該是通往僕役休息室的
通道，南方的通道通向你剛才來的門廳。
C_LONG
    );
    set("item_desc", ([
        "throne" : "王座上雕刻著一隻獨眼怪 (ogre)，看起來很嚇人。\n",
	"ogre" : "這獨眼怪的眼睛似乎是某種按鈕 (button)。\n"
        ]) );
    set("exits", ([ 
	"south" : AREA"eda3",
	"west" : AREA"eda5",
	"east" : AREA"eda6"
	 ]) );
    reset();
}

void init()
{
    add_action("to_push", "push");
}

int to_push(string s)
{
    object p;
    p = this_player();

    if (s == "button")
    {
 	write("你按了一下獨眼怪的眼睛，但是它馬上又彈了回來。\n\n");
        write("你忽然發現，獨眼怪似乎正狠狠地瞪著你! 令你一陣暈眩!\n\n");
	p->set_temp("block_command", 1);
        call_out("recover", 15, p);
	return 1;
    }
    
    return notify_fail("你想按什麼?\n");
}

int recover(object p)
{
    p->set_temp("block_command", 0);
    tell_object(p, "當你回過神來時，你發現眼前的景物已經變了...\n");
    p->move(AREA"eda7");
    return 1;
}

