//Deathland/holyplace/r06.c
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
在這裡你看到一些很大的建築,雖然這些建築沒有甚麼美感,但是你能感覺到一種
嚴肅且莊重的氣氛,四周充滿著柔和的亮光,讓人感到平安,祥和.你已經到達矮人的聖
地了.這裡北邊的深淵又大又深,而對面就是矮人礦坑.地上有著軌道的痕跡,似乎運礦
車專用的道路.
CLong
);
set("direction","south");
set("exits",([
             "south":Deathland"/holyplace/r05",
             ]));
reset();
}
