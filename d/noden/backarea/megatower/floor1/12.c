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
這裡是摩天塔的內部第一層的西南角, 這塔似乎是年久失修, 到處可見破碎的瓦
片與石塊, 還有著一些奇奇怪怪的足跡印在地上. 這地方由於終年不見陽光, 顯得十
分的陰暗潮溼. 
CLong
);
  set("objects",([
      "goblin#01":Monster"/goblin01",
      "goblin#02":Monster"/goblin01",
      "goblin#03":Monster"/goblin01",
      ]) );
  set("exits",([
               "east" :Megatower"/floor1/22",
               "north":Megatower"/floor1/13",
               "southeast":Megatower"/floor1/21",
               
             ]));

::reset();
}
