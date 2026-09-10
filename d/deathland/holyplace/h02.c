//Deathland/holyplace/h02.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","矮人聖地的祭壇");
  set_long(@Long
Long
,@CLong
在這裡你能感覺到一種神聖且莊嚴的力量,四周柔和的亮光更使得這地方充滿著祥
和的氣氛,你目前的位置是在矮人聖地的祭壇.有四根很大的圓柱聳立與四個角落,中間
是一個大的祭壇,而有個巨大的神像矗立其中,明顯的是矮人的神,Yang.另外,有著十二
團熊熊的烈火以一個圓形圍繞著祭壇,然而你卻不會覺得那些火的火光很刺眼,相反的
那些火有種柔和的感覺.南方有一個造形奇特的小屋,你或許應該去看看.
CLong
);

set("c_item_desc",([
    "fire":"十二團熊熊的烈火.以一個圓形圍繞著祭壇\n",
    "statue":"一座巨大的神像.\n",
    "altar":"一座空無一物的祭壇.\n"
    ]) );
set("exits",([
             "south":Deathland"/holyplace/h03",
             "west":Deathland"/holyplace/h05",
             "east":Deathland"/holyplace/r05",
             ]));

set("objects",([
    "guard":Monster"/guard08",
    ]) );
reset();

}
