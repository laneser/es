
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("swamp of GreyIsland","灰暗之島的沼澤");
  set_long(@Long
Long
,@CLong
一個黑漆漆的沼澤, 沼澤下似乎有著可怕的生物想把你拖下去, 你必須小心謹慎
你的每一步. 越往東走沼澤的水就越深, 而且你的視線也被霧幾乎完全地遮住了. 這
地裡你已經無法清楚地看到四周的狀況了, 只知道你的腳已經快深陷於沼澤裡了.

CLong
);

set("exits",([
     "north":Deathland"/island/swamp17",
     "south":Deathland"/island/swamp19",
     ]) );
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exit_invisble",1);     

::reset();
}

string search_here()
{
     return "當你仔細尋找這裡的時候, 你發現西方沼澤的水面上似乎很奇怪,\n"
            "想想原來是上面竟然連一片樹葉也沒有, 你跟本無法通到那個地方\n"
            ". 似乎你必須尋找其它的方法才行.\n";
}


