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
這裡位於是摩天塔的內部第一層的西邊房間裡的一個角落, 除了一些到處可見破碎
的瓦片與石塊之外, 還有著一些航海用的大水桶堆與此地.
CLong
);
  set("exits",([
               "north" :Megatower"/floor1/03",
             ]));

::reset();
}
