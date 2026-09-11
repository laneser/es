
#include "zeus.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("段家礦坑入口");
  set_long(@CLong
這裡是礦坑的入口.你能看到的是一個周圍的巖壁充滿著被挖掘的痕跡以及
用木頭架設著以免塌陷的巖洞.在地上有鐵軌鋪設著.北邊傳來陣陣的水聲，
CLong
);
   

set("exits",([
		"south" : "/d/eastland/goomay/entrance",
             "north":ZROOM"/bridge" ]));

    reset();
#include <replace_room.h>
}
