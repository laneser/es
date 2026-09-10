#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long(
@LONG_DESCRIPTION
這片空地崎嶇不平，到處都是黑色的石頭，深褐色的土壤，你一看到這地型地物
就知道一定是火山爆發後的殘留物，而且你也覺的這裡蠻熱的，你猜一定有火山在這
附近。你發現不遠的前方有個城郭似的建築，還有個吊橋，橋旁似乎還有人的樣子，
你想那可能就是可怕的矮靈族部落，但好奇心卻驅使你想過去瞧瞧。
LONG_DESCRIPTION
	);
set( "exits", ([
     "near" : OGROUP"warea1",
     "north" : ONEW"wild17",
     "southwest" : ONEW"wild13",
     ]) );
set( "pre_exit_func", ([
     "near":"to_near" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}

int to_near()
{
  write("你向吊橋走了過去。\n");
  return 0;
}
