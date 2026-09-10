#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿走廊");
	set_long( 
@LONG_DESCRIPTION
一條長長的走廊，你看到牆上有著壁畫，是矮靈族中慶典時，樂人和舞者賣力
獻技助興的情形，大家圍著廣場中的營火盡情歡樂，裸體的是舞者，坐在一旁用手
拍打，或吹奏樂器的，都是樂人。往南可以通到正殿，往西可以到左殿，往北可通
往神殿深處。
LONG_DESCRIPTION
	);
set( "exits", ([
     "southeast" : OTEMP"temple5",
     "west" : OTEMP"temple17",
     "north" : OTEMP"temple11",
     ]) );
reset();
#include <../replace_room.h>
}
