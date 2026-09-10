#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("山腰");
	set_long( 
@LONG_DESCRIPTION
你站在山腰處，抬頭往上望去，心裡想著要到達火山頂還一大段距離，休息一下
吧。那聳立雲霄的火山山口似忽還會有陣陣濃煙冒出，不知何時還會再爆發，你覺的
這裡非常的熱，不可能有生物能在這裡生存下去，這裡到處都是火山岩和浮石，這座
由火山岩所構成的火山，由於到處是巨大的裂縫，因此想到達山頂是相當困難的。
LONG_DESCRIPTION
	);

set( "exits", ([
     "northeast" : ONEW"varea5",
     "north" : ONEW"varea3",
     "down" : ONEW"varea1" ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
