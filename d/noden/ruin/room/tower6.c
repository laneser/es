// tower6.c

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
    switch(random(3))
    {
	case 0: set("exits", ([
		    "east" : AREA"tower7",
		    "south" : AREA"tower5"
		    ]));
		break;
	case 1: set("exits", ([
                    "west" : AREA"tower7",
                    "south" : AREA"tower5"
                    ]));
                break;
	case 2: set("exits", ([
                    "north" : AREA"tower7",
                    "south" : AREA"tower5"
                    ]));
                break;
    }
    reset();
}


