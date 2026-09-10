// tower1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔術師塔．出口");
    set_long(@C_LONG
這裡是魔術師塔的出口，四周堆滿著各種生物的骷髏，肅殺詭秘的氣氛令
人毛骨悚然。出口的大門旁立著塊石碑，上面寫著：「HASLAVISTA BABY!」。
C_LONG
	    );

    set("exits", (["north" : AREA"tower0"]));
    set("item_desc", ([
	"slab" : "一塊殘破的石碑，上面寫著：「向真神祈禱」。\n"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_pray", "pray");
}

int to_search(string arg)
{
    write("你找了又找，只看到地上有塊小石碑 (slab)。\n");
    return 1;
}

int to_pray()
{
    write("你跪下來祈禱，祈禱些什麼呢? ....\n");
    this_player()->move(AREA"rose4");
    return 1;
}

