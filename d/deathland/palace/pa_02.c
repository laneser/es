
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set("light",1);
set_short("The road toward the sleeping hall","通道");
  set_long(@Long
Long
,@CLong
連接大廳與起居室的通道.通道兩旁的牆壁分別掛著現任矮人國王莫拉德五世
(Molader V)以及他死去的大兒子法拉第的畫像(icons).
CLong
);

set("c_item_desc",([
    "icons":"莫拉德五世看起來一副和藹可親的樣子,而法拉第看起來則像是你的"
            "老朋友.\n"         
    ]) );    
set("search_desc",([
     "icons": "@@to_search_icons",
     "icon": "@@to_search_icons",
     ]) );    
set("exits",([
               "west":Deathland"/palace/pa_01",
               "east":Deathland"/palace/pa_05",
             ]));
::reset();
}

int to_search_icons()
{
     write("你發現有一個通道藏在畫像後,於是你便鑽進去裡面一探究竟。\n");
     this_player()->set_explore( "deathland#10" );
     this_player()->move_player(Deathland"/palace/pa_0b","SNEAK");
     return 1;
}
