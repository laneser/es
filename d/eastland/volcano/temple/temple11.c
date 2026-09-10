#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long(
@LONG_DESCRIPTION
一條長長的走廊，你看到牆上有著壁畫，畫著火山爆發時的景像，火山塵聳入
雲霄，所有的飛禽鳥獸正四處奔竄。往南可以通到正殿，往北可通向神殿深處。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OTEMP"temple9",
     "north" : OTEMP"temple13",
     ]) );
reset();
#include <../replace_room.h>
}
