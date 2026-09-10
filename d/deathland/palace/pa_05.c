
#include "../echobomber.h"

inherit DOORS;
inherit ROOM;
void create()
{
	::create();
  set("no_monster",1);
  set("light",1);
  set_short("","起居室");
  set_long(@Long
Long
,@CLong
矮人國王莫拉德五世的起居室.目前莫拉德皇族的成員只剩下國王莫拉德五世
,皇后莉莉絲(Lilies),以及他們的二兒子艾爾(Air).大兒子法拉第(Falady )在一
一次的巨人入侵時為了阻止巨人祭司哈得瑞德屈裡(Hotredchili)的黑暗魔法而英
勇的犧牲了,而巨人的攻擊也因此受挫.但是戰爭並未因此結束.矮人族正需要一個
勇敢的英雄來幫助他們.
東方是皇后莉莉絲的寢宮,而南,北方則是兩個兒子的房間.
CLong
);
set("exits",([
               "east":Deathland"/palace/pa_08",
               "north":Deathland"/palace/pa_09",
               "south":Deathland"/palace/pa_0a",
               "west":Deathland"/palace/pa_02",
             ]));

set("objects",([
    "king":Monster"/king",
   ]) );


create_door("east","west",([
             "name":"gold door",
             "c_name":"金色的門",
             "keyword":({"gold door","door",}),
             "c_desc":"金色的門",
             "status":"locked",
             "desc":"a gold door",
             "lock":"ECHO_DWARF_CITY_1",
                     ]) );
  ::reset();
}
