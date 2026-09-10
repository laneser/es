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
這裡位於是摩天塔的內部第一層的西南方的一個角落, 這塔似乎是年久失修, 到
處可見破碎的瓦片與石塊, 還有著一些奇奇怪怪的足跡印在地上. 這地方由於終年不
見陽光, 顯得十分的陰暗潮溼. 
CLong
);
  set("objects",([
      "goblin":Monster"/goblin01",
      ]) );
  set("exits",([
               "east" :Megatower"/floor1/30",
             ]));
 
::reset();
}
