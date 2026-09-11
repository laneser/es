
#include "zeus.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，比起其他的礦坑，這地方似乎寬大了許多，四周用
許多的木條支撐著，地上散佈了許多巨大的腳印，看起來並不像普通人類所有．
CLong
);
   

set("exits",([
             "south":ZROOM"/bridge",
             "northeast":ZROOM"/center1"
             ]));
reset();
#include <replace_room.h>
}
