
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("礦坑大廳");
  set_long(@CLong
這是座十分寬闊的地方，有許多的矮凳子，可見此地是礦工們休息的地方，
而整個房間被開鑿成八卦型，宛如蜘蛛網的中心點，是控制礦坑內各出口的重要
樞紐，要到達礦坑的任何角落，都必須經過此地．
CLong
);
   

set("exits",([
             "southwest":ZROOM"/mine01",
             "east":ZROOM"/center2",
             "west":ZROOM"/hospital",
             "north":ZROOM"/center4",
             ]));
set("exit_suppress",({"west"}));

reset();
#include <replace_room.h>
}