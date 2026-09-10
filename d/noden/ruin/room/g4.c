// g4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("廢棄的花園");
    set_long(@C_LONG
你來到了一個廢棄的花園，到處長滿了雜草和青苔。這裡的空氣充滿著肅
殺的氣氛，似乎連你身上的血液也快要為之凝結起來。雜草中似乎隱藏著一個
什麼東西，但是你看不清楚。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"g10",
	"east" : AREA"g9",
	"west" : AREA"g5",
	]) );
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write(@DIRE
草叢裡有個小平臺，上頭刻著：

		└
	      ↑  △
DIRE
	);
    return 1;
}

