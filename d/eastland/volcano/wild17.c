#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("空地");
	set_long( 
@LONG_DESCRIPTION
這片空地崎嶇不平，甚至有幾條巨大的裂縫，把這塊空地弄成看起來四分五裂的，
到處都是黑紅色的石頭，黑色的土壤，使你一看到這地型地物就知道一定是火山爆發後
的殘留物，而且你覺得這裡相當熱，往東北方望去，果然不錯，一座巨大的火山矗立在
那兒。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast" : ONEW"varea1",
     "southeast" : ONEW"wild20",
     "southwest" : ONEW"wild18",
     "south" : ONEW"wild16",
     "northwest" : ONEW"wild14",
     ]) );
set( "objects", ([
     "mrat":OMONSTER"mrat" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
