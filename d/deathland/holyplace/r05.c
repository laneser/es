//Deathland/holyplace/r05.c
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
地了.地上有著軌道的痕跡,似乎是運礦車專用的道路.西邊似乎是一個祭壇,你能看到
一座很大的神像.
CLong
);
set("direction","south");
set("exits",([
             "north":Deathland"/holyplace/r06",
             "west":Deathland"/holyplace/h02",
             "south":Deathland"/holyplace/r07",
             "east":Deathland"/holyplace/r04",
             ]));
reset();
}
