
#include "zeus.h"

inherit ROOM;
int paper_num;
void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，偶而可以聽到人們的吆喝聲，從聲音中可以聽出充滿
了興奮與快樂的味道，在前方一定有一個讓人流連忘返的快樂天堂．
CLong
); 

set("exits",([
             "north":ZROOM"/wineroom02",
             "southeast":ZROOM"/center4"
             ]));

reset();
#include <replace_room.h>
}