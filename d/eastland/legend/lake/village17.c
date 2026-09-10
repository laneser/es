#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("漁村道路");
        set_long( 
@LONG
你正走在漁村的道路上，迎面撲來的是一股濃濃的腥臭味；在地上，縱橫交錯
著血水枯乾的小河；一團團蒼蠅，正汲汲於腐爛的魚肉上，不時發出嗡嗡地鳴聲。
晦暗不明的天空，烏雲團簇好似一隻只正在張牙舞爪的野獸，野獸正惡狠狠地瞪著
你，好像對著你說：『快來吧，快來吧，我的食物』。東和西邊是一堆和人同高度
的野草；道路往南、北邊延申。
LONG);
    set( "exits", ([
         "south":LAKE"village10",
        "north":LAKE"village18"
    ]) );
    set("objects",([
        "boy#1":LMONSTER"boy",
        "boy#2":LMONSTER"boy",
        "girl#1":LMONSTER"girl",
    ]) );
    ::reset();
}
