// tower5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔術師塔．第二層");
    set_long(@C_LONG
這裡是魔術師塔的第二層，地板上畫滿了密密麻麻的奇特咒文，似乎是用
來禁制某種可怕的生物用的。空氣中充滿了腐屍的氣味，你的直覺告訴你如果
不快點設法離開這個地方，恐怕不久之後你也會變成一具屍體了。
C_LONG
	    );
    set("exits", ([
	"east" : AREA"tower4",
	"north" : AREA"tower6"
	]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    write(@HINT
你看見地上寫著：

	零啊零啊是這裡，
	一啊一啊嘻嘻嘻，
	二啊二啊哩哩哩，
	三啊三啊滾出去，
	四啊四啊死回去，
	五六七啊跑跑跑，
	八九十還是嘻嘻嘻，
	迷宮亂亂真有趣，
	難難難難難死你。

這 .... 這是哪一國的兒歌啊? ....
HINT
	);
    return 1;
}

