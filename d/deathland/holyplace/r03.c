//Deathland/holyplace/r03.c
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
地了.西南方有一處特別奇特的小屋,\或許你應該進去看看.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/r04",
             "east":Deathland"/holyplace/r01",
             "southwest":Deathland"/holyplace/h04",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();
}
