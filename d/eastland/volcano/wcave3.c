#include "oldcat.h"

inherit ROOM;

void create()
{
        ::create();
        set_short( "地道盡頭" );
        set_long(
@LONG
你站在地道的盡頭，一個小土階往上通去，不必懷疑，上面就是出口了。
LONG
        );
	set( "exits", ([
        "up" : ONEW"varea5"
	]) );
        set("objects", ([
            "oregon":OMONSTER"oregon",
            ]) );
        reset();
#include <replace_room.h>
}
