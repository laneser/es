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
你，好像對著你說：『快來吧，快來吧，我的食物』。漁村道路往南、北邊延申，
西邊有一片小空地，東邊有一間矮房子。
LONG);
    set("c_item_desc",([
        "矮房子":"一間破舊的老房子，屋頂沒了，只留下三面斑白的牆壁，想必是沒人住。\n",
        "小空地":"一塊小小的空地，地上野草叢生。\n"   
    ]) );            
    set( "light",1);
    set( "exit_suppress", ({
          "west" }) );
             
    set( "exits", ([
          "north":LAKE"village17",
          "west":LAKE"village19",
         "south":LAKE"village9"
    ]) );
    ::reset();
}
