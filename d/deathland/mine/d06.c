
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the small pool","小水池");
  set_long(@Long
Long
,@CLong
一個小小的水池,然而卻堆積滿了骨骸,這裡應該存在著一個很強的怪物.
CLong
);
set("item_func",([
    "skeleton":"look_skeleton",
    ]) );
set("exits",([
             "out":Mine"/d05",
             ]));
set("objects",([
    "siren":Monster"/siren",
    ]) );
reset();
}

int look_skeleton()
{
    write("一堆骨骸,似乎有被啃過的痕跡\n");
    this_player()->set_explore("deathland#6");
    return 1;
}