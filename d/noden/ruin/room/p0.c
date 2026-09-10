// p0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("卡榭布蘭卡宮．門廳");
    set_long(@C_LONG
眼前所見是一片美麗的景象，嬌豔的香水百合映著巍峨的廊柱，空氣中充
滿著馥郁的香氣，以及蝴蝶翩翩飛舞的身影。在這裡，你頓時覺得心情舒暢不
已。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"p1"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write("別找啦，你過關啦，女王的寢宮不是讓你逛大街的地方 :p\n");
    return 1;
}

