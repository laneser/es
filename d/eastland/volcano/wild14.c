#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long(
@LONG_DESCRIPTION
這片空地崎嶇不平，到處都是紅、黑色的石頭，以及深褐色的土壤，你一看到這地
型地物就知道一定是火山爆發後的殘留物，而且你也覺的這裡蠻熱的，你猜一定有火山
在這附近，遠處似乎還傳來陣陣鼓聲，那獵人頭族的部落一定也距離這裡不遠。
LONG_DESCRIPTION
	);
set( "exits", ([
     "southeast" : ONEW"wild17",
     "southwest" : ONEW"wild11" ]) );
set( "objects", ([
     "adventurer":OMONSTER"adventurer" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
