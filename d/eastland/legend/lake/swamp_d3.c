#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼澤地底洞穴");
    set_long(@LONG
咚的一聲，你撞著了洞穴的頂部。你揉了揉弄痛的地方順便環顧了一下四周，只
見前方一遍白茫茫的霧氣，地面上是一顆一顆的大石頭上面長著深綠色的青苔。越見
低矮的空間使你猜想前面應該沒有通路了。
LONG
    );
    set("exits",([
            "north":LAKE"swamp_d1"
    ]) );
    set("objects",([
        "beholder":LMONSTER"beholder1"
    ]) );    
    ::reset();
}

