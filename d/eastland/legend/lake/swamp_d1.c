#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼澤地底洞穴");
    set_long(@LONG
你來了沼澤底下一個奇怪的洞穴。沒有令人掩鼻的腐朽惡臭，不見遍地的骸骨，
也沒有兇惡駭人的沼澤毒物怪獸；相反的，這裡的空氣清新的讓人渾身沒有一個毛孔
不暢快，四周有著閒適的寧靜。北壁下一條淺淺的地下泉水蜿蜒流經，黯淡的光線下
隱隱約約可以看出東，南方各有一條通道，不知道通往什麼地方。
LONG
    );
    set("exits",([
            "eastdown":LAKE"swamp_d2",
            "south":LAKE"swamp_d3",
            "up":LAKE"swamp8",
    ]) );
    set("objects",([
          "icetoad#1":LMONSTER"icetoad",
          "icetoad#2":LMONSTER"icetoad",
          "icetoad#3":LMONSTER"icetoad",
    ]) );
    ::reset();
}

