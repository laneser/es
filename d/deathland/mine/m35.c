
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" Drawf mine ","矮人礦坑");
  set_long(@Long
Long
,@CLong
這裡是礦坑的深處.你能看到的是一個周圍的巖壁充滿著被挖掘的痕跡以及
用木頭架設著以免塌陷的巖洞.在地上有鐵軌鋪設著.專供運礦車通行使用.然而
這裡是鐵軌的盡頭,前面的路似乎被一堆塌陷的石塊與木頭擋住了去路.
CLong
);
set("direction","block");
set("exits",([
             "north":Mine"/m23",
             ]));
#include <replace_room.h>
}
