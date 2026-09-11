#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long(
@LONG_DESCRIPTION
一條長長的走廊，一尊尊的神像，被畫於牆壁上，那些怪異的狂舞形姿，充滿了
奇特的氣氛，往南可以通到正殿，往北可通向後院。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OTEMP"temple10",
     "north" : OTEMP"temple14",
     ]) );
reset();
#include "../replace_room.h"
}
