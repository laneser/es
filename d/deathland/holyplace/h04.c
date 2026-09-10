//Deathland/holyplace/h04.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","矮人聖地");
  set_long(@Long
Long
,@CLong
你目前處在一間魔法小屋內,四周的力場十分的強烈,似乎這裡有著一種強大的魔力
.但是這個屋子空空蕩蕩的,除了房屋中間有一個奇怪的水晶球(crystalball),以及在水
晶球的旁邊有一個標示(sign).
CLong
);

set("c_item_desc",([
    "sign":"警告:當你碰觸(touch)這顆水晶球的時候,你將被傳離這個神聖的地方.\n",
    "crystalball":"一顆魔法水晶球.\n",
    ]) );

set("exits",([
             "northeast":Deathland"/holyplace/r03",
             ]));
             

reset();
}

void init()
{
   add_action("to_touch","touch");
}

int to_touch(string str)
{
    if (!str||str!="crystalball") return 0;
    
    write("當你碰到水晶球的一剎那,你整個人忽然騰空,然後到達了另一個地方.\n");
    
    this_player()->move_player(Deathland"/city/church",({
    "..\n","%s忽然整個人消失的無影無蹤.\n","..\n","在一陣耀眼的強光下,%s出現在這個地方.\n"
    }),"");
    return 1;
}
