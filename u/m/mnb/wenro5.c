// wenro5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("祭壇");
    set_long(@C_LONG
這裡有個被樹林環繞著的祭壇 (altar)，祭壇上有個和人身一樣大小的美
麗雕像 (statue) 。雖然景緻非常地優美，但是你總覺得空氣中瀰漫著一股難
以形容的憂傷氣氛，與前頭的歡樂氣息迥然不同。這氣氛難道是那個年輕人造
成的嗎？
C_LONG
	    );
    set("exits", (["east" : AREA"wenro4"]));
    set("objects", (["carmue" : MOB"carmue"]));
    set("item_desc", ([
	"altar" : "一個花崗石祭壇，也許可以供奉 (dedicate) 些什麼。\n",
	"statue" : "一座刻的栩栩如生的美女雕像。\n"
	]));
    reset();
}

void init()
{
    add_action("do_dedicate", "dedicate");
    add_action("do_kiss", "kiss");
}

int do_dedicate()
{
    object f; 
    if (f = present("casablanca", this_player()))
    {
	write("你把香水百合供奉在祭壇上。\n");
	this_player()->set_temp("lilia_dedicate", 1);
	f->remove();
	return 1;
    } 
    else
	return notify_fail("你身上沒有什麼可供奉的東西。\n");
}

int do_kiss(string arg)
{
    object p;

    p = this_player();

    if (arg == "statue")
    {
	if (p->query_temp("lilia_dedicate") != 1 &&
	    present("carmue", this_object()))
	{
	    write("你發現卡謬正惡狠狠地瞪著你，還是別親的好。\n");
	    return 1;
	}
        else    
	{
	    write("你輕輕地親吻了一下神像的臉，突然間感到一陣天旋地轉 ...\n");
	    p->move(AREA"wenro6");
	p->set_explore("noden#46");
	    p->delete_temp("lilia_dedicate");
	    return 1;
	}
    }
    else
	return notify_fail("你想親什麼?\n");
}

