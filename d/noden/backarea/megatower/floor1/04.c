#include "../megatower.h"

inherit ROOM;
inherit Megatower+"/daemon/trap";

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的內部");
  set_long(@Long
Long
,@CLong
這裡位於是摩天塔的內部第一層的西邊房間裡的一個角落, 除了一些到處可見破碎
的瓦片與石塊之外, 這裡地上有一些小洞, 排列著很整齊的樣子, 而且還冒著熱氣.
CLong
);
  set("exits",([
               "south" :Megatower"/floor1/03",
             ]));

::reset();
}

void init()
{
     ::trap();
}
