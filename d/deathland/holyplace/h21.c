
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("strange fog","奇怪的霧裡");
  set_long(@Long
Long
,@CLong
在這裡你只見霧越來越大了, 然而西邊的紅色火團卻很明顯, 從這裡你就能感
受到那團火的妖氣. 究竟那是什麼呢? 
CLong
);

set("exits",([
             "east":Deathland"/holyplace/h19",
             "west":Deathland"/holyplace/h23",
             ]));
reset();
}
