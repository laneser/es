//Deathland/holyplace/h05.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set("no_monster",1);
  set_short(" Drawf holy place ","矮人聖地");
  set_long(@Long
Long
,@CLong
在這裡你看到一些很大的建築,而且四周充滿著柔和的亮光,你目前位於矮人聖地.
在西邊的通道上有一層魔法牆,似乎在防止一些可怕的生物入侵.從這裡往東,你能到達
矮人祭壇,而西邊則是一個未知的區域.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h06",
             "east":Deathland"/holyplace/h02",
             ]));
set("objects",([
    "guard":Monster"/guard07",
    ]) );

reset();

}
