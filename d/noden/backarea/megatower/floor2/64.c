#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The 2rd floor of Mega Tower","摩天塔的二樓");
  set_long(@Long
Long
,@CLong
你到達了摩天塔的第二層,  這裡到處可見破碎的瓦片與石塊. 往南有個走廊,通往塔
的深處. 還有一個階梯, 向下通向摩天塔的底層.
CLong
);
  set("exits",([
               "south" :Megatower"/floor2/63",
               "down"    :Megatower"/floor1/64",
             ]));

::reset();
}

