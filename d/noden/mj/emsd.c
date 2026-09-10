//emsd.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("明教");
    set_long(@C_LONG
這是一個用黃金造成的神殿，燦爛的光芒四射，在神殿中央有個祭壇
(altar),祭壇上有個和人身一樣大小的莊嚴的神像(statue)。看來你
到了明教的神聖之地。
C_LONG
	    );
    set("exits", (["east" : AREA"wenro4"]));
    set("objects", (["carmue" : MOB"carmue"]));
    set("item_desc", ([
        "altar" : "一個用完整的鑽石雕刻的祭壇，也許可以供奉 (gongxian) 些什麼。\n",
        "statue" : "一座刻的栩栩如生的教宗寒鴉的雕像，威嚴而肅穆。\n"
	]));
    reset();
}

void init()
{
    add_action("do_gongxian", "gongxian");
    add_action("do_bow", "bow");
}

int do_dedicate()
{
    object f; 
    if (f = present("torch", this_player()))
    {
        write("你把火把虔誠的供奉在祭壇上。\n");
	this_player()->set_temp("lilia_dedicate", 1);
	f->remove();
	return 1;
    } 
    else
        return notify_fail("你身上沒有什麼可供奉的東西,寒鴉的眼睛好象眨了眨。\n");
}

int do_bow(string arg)
{
    object p;

    p = this_player();

    if (arg == "statue")
    {
	if (p->query_temp("lilia_dedicate") != 1 &&
	    present("carmue", this_object()))
	{
            write("你發現羅納爾多正惡狠狠地瞪著你，小心你的屁屁。\n");
	    return 1;
	}
        else    
	{
            write("你虔誠的向神像鞠了一躬，突然間一道神奇的彩虹注入你的身體 ...\n");
	    p->move(AREA"wenro6");
	p->set_explore("noden#46");
	    p->delete_temp("lilia_dedicate");
	    return 1;
	}
    }
    else
        return notify_fail("你想做什麼?\n");
}

