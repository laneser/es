#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long( 
@LONG_DESCRIPTION
這片空地崎嶇不平，到處都是黑色的石頭，深褐色的土壤，你一看到這地型
地物就知道一定是火山爆發後的殘留物，而且你也覺的這裡蠻熱的，你猜一定有
火山在這附近，而且那矮靈族的部落必定離這裡不是很遠。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast" : ONEW"wild17" ]) );
set( "objects", ([
     "deadman":OMONSTER"deadman" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
