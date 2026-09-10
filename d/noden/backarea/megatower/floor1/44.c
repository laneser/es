#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的內部");
  set_long(@Long
Long
,@CLong
這裡是摩天塔的內部第一層, 這塔似乎是年久失修, 到處可見破碎的瓦片與石塊,
還有著一些奇奇怪怪的足跡印在地上. 這地方由於終年不見陽光, 顯得十分的陰暗潮溼
. 慢慢地你覺得塔內的空氣越來越糟糕, 還有一股肅殺的氣氛向你漸漸地逼近. 一種忽
遠忽近有節奏的怪怪的聲音從塔的正中央傳出, 你完全不能理解這個奇怪的高塔.
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/34",
               "north":Megatower"/floor1/45",
               "east" :Megatower"/floor1/54",
               "south":Megatower"/floor1/43",
             ]));

::reset();
}
