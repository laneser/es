//Deathland/holyplace/h03.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short("mystic house","神秘小屋");
  set_long(@Long
Long
,@CLong
一處神秘的小屋,裡面的東西雜亂無章,桌子上擺滿了奇奇怪怪的瓶子,你無法了
解這個地方的人正在做甚麼.
CLong
);

set("exits",([
             "north":Deathland"/holyplace/h02",
             ]));
reset();
}
