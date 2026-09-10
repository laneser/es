#include "../megatower.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
  set("light",0);
  set_short("Mega Tower","摩天塔的內部");
  set_long(@Long
Long
,@CLong
這裡是摩天塔的內部第一層西邊的一個房間, 這塔似乎是年久失修, 到處可見破
碎的瓦片與石塊, 還有著一些奇奇怪怪的足跡印在地上. 這地方由於終年不見陽光, 
顯得十分的陰暗潮溼. 慢慢地你覺得塔內的空氣越來越糟糕, 還有一股肅殺的氣氛向
你漸漸地逼近.  
CLong
);
  set("exits",([
               "east" :Megatower"/floor1/46",
               "south":Megatower"/floor1/35",
               "west" :Megatower"/floor1/26",
             ]));
  create_door("south","north",([
             "name":"stone door",
             "c_name":"石門",
             "keyword":({"stone door","door",}),
             "c_desc":"石門",
             "status":"locked",
             "desc":"a stone door",
             "lock":"MEGA_TOWER_1_n",
                     ]) );

::reset();
}
