// wenro4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("樹林");
    set_long(@C_LONG
眼前所見是一片青翠的樹林，林子裡不時傳來陣陣的歌聲，伴著枝頭上悅
耳的鳥囀，織成一曲動人的樂章。沐浴在這天籟之中，你頓時覺得心情舒暢不
已，也想隨著這音樂放聲高歌。
C_LONG
	    );
    set("exits", ([
	"west" : AREA"wenro5",
	"south" : AREA"wenro3"
	]));
    set("objects", (["bard" : MOB"bard"]));
    set("item_desc", ([
	"casablanca" : "香水百合，花中的女王，花語是偉大的愛。\n"
	]));
    reset();
}

void init()
{
    add_action("do_search", "search");
    add_action("do_pick", "pick");
}

int do_search(string arg)
{
    write("除了角落裡長了些香水百合 (casablanca) 之外，沒什麼特別的東西。\n");
    return 1;
}

int do_pick(string arg)
{
    object f;

    if (arg == "casablanca")
    {
        f = new(OBJ"casablanca");
        f->move(this_player());
        write("你摘下一朵香水百合。\n");
	return 1;
    }
    else if (arg == "flower")
	return notify_fail("你想摘什麼花?\n");
    else	
	return notify_fail("你想做什麼?\n");
}

