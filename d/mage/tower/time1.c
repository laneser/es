#include "../echobomber.h"

inherit ROOM;

void create()
{
         ::create();
     set_short("the ruin","白魔法通道");
     set_long(@Long
Long
,@CLong
這裡似乎這座城堡的中心，可能是去白魔法城的通道。
CLong
);
     set("objects",([
         "wight":"d/mage/tower/god",
         ]) );
     set("exits",([
    "west" : "/d/mage/tower/mage_guild.c" ,
    "north" : "/d/mage/tower/time.c",
         ]) );
     set("pre_exit_func",([
         "north":"to_north",
         ]) );
     reset();
}

int to_north()
{
    if (present("wight")) {
      write(can_read_chinese() ?
            "你被地獄魔神擋住了去路 .\n" :
            "you are blocked by the wight.\n"
           );
      return 1;     
      }

    return 0;
}
