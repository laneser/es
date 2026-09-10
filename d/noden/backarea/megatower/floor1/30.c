#include "../megatower.h"

inherit ROOM;

void create()
{
	::create();
  set("light",0);
  set_short("The Entrance of Mega Tower","摩天塔的入口");
  set_long(@Long
Long
,@CLong
你已經進入摩天塔的內部第一層了, 這塔似乎是年久失修, 到處可見破碎的瓦片
與石塊, 這地方是高塔的入口, 有一個告示牌(plaque)橫躺與地上, 上面的字跡有些
模糊, 但是對你來講了解它的意義卻沒什麼困難.
    這座塔是什麼人建造的, 建造它的目的又是為了什麼呢? 種種的秘密待你去探查.
CLong
);
  set("exits",([
               "west" :Megatower"/floor1/20",
               "east" :Megatower"/floor1/40",
               "south":Megatower"/outside",
               "north":Megatower"/floor1/31",
             ]));

  set("item_func",([
      "plaque":"look_plaque",
      ]) );
::reset();
}

int look_plaque()
{
    write(
          "**********************************\n"
          "*給來到這裡的朋友們,             *\n"
          "*  有著數以萬計的寶藏送給你.     *\n"
          "*    ------海盜凱斯特(Keist)-----*\n"
          "**********************************\n"
          );
    return 1;
}
