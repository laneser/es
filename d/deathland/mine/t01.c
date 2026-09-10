
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("Mine","礦坑的深處");
  set_long(@Long
Long
,@CLong
這裡是礦坑的深處. 北邊有一堆亂石把通道給堵住了, 目前除了南邊的一個
窄窄的裂縫, 你沒有任何的出路. 
CLong
);
set("direction","block");
set("exits",([
             "south":Mine"/t02",
             ]));
#include <replace_room.h>
}
