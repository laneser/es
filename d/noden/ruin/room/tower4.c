// tower4.c

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
    set("objects", (["jitter" : MOB"jitter"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search()
{
    if (this_player()->query_temp("lilia_direction") == 1)
    {
	write("你定睛一看，西邊果然有個小門，暗暗地看不太清楚 ....\n");
	set("exits", (["west" : AREA"tower5"]));
        return 1;
    }
    else
        return 0;
}

