#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
        ::create();
    set_short("沼澤");
        set_long( 
@LONG
啊！毒氣，糟糕，你走進了最危險的沼澤地，四周都是足以致命的瘴氣。但是
奇怪的是，這裡不像其他沼澤地充滿各式各樣吃人的巨型怪物，也沒有人類的□骨
，相反的，這裡到處都是巨型沼澤怪獸的殘骸；雖然你已經站在這裡好一段時間，
但卻沒有任何一隻怪物追來。你四下搜尋，發現西邊的空氣中瀰漫著一股濃厚的血
腥惡臭，這股惡臭比沼氣更刺鼻，更難聞，而且每隔一段時間就傳來一陣怪嘯，聲
音有如牛哞，但卻遠比其響亮。你想，一定是更恐怖的怪物。
LONG
    );
    set( "exit_suppress", ({
           "east","north","west","south" }) );
    set("exits",([
            "east":LAKE"swamp5",
            "north":LAKE"swamp3",
            "west":LAKE"swamp7",
            "south":LAKE"swamp3"
       ]) );
    reset();
}

