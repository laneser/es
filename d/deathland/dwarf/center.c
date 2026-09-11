
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The new_trained_soldier center","新兵訓練中心");
  set_long(@Long
Long
,@CLong
這裡是專門將年輕的矮人訓練成勇猛的戰士的地方.每個矮人的戰鬥生涯幾乎皆從此
處開始.
CLong
);

set("exits",([
               "out":Deathland"/dwarf/village_04",
             ]));
set("objects",([
    "teacher":Monster"/soldier03",
    "newsoldier#1":Monster"/soldier04",
    "newsoldier#2":Monster"/soldier04",
    "newsoldier#3":Monster"/soldier04", 
    ]) );
::reset();
#include "../replace_room.h"
}

