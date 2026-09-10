//Deathland/holyplace/r07.c
//Created by Echobomber Eastern.Stories

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
在這裡你看到一些很大的建築,而且四周充滿著柔和的亮光,你已經到達矮人的聖地了.
一些破碎的運礦車被放置於地上,而南邊有的柔軟的牆壁,似乎用來降低碰撞的衝擊力.
CLong
);
set("direction","block");
set("exits",([
             "north":Deathland"/holyplace/r05",
             ]));
reset();
}
