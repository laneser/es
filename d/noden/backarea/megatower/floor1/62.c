#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的內部");
  set_long(@Long
Long
,@CLong
這裡位於是摩天塔的內部第一層的東邊房間裡的一個角落, 除了一些到處可見破碎
的瓦片與石塊之外, 這裡地上有著營火, 似乎有著人類活動的跡像.
CLong
);
  set("exits",([
               "north" :Megatower"/floor1/63",
             ]));

::reset();
}

