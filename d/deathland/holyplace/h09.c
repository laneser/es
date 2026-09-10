// Deathland/holyplace/h09.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","奇怪的地方");
  set_long(@Long
Long
,@CLong
一個奇怪的地方, 四處的黑影無聲無息地向你侵襲而來. 四面都是岩石, 你似乎
是通過岩石來到這個地方. 你必須瞭解那邊的巖壁是假的, 這樣你才能離開這裡.
CLong
);

set("exits",([
             "north":Deathland"/holyplace/h14",
             "east":Deathland"/holyplace/h22",
             ]));
set("exit_invisble",1);
reset();
}

