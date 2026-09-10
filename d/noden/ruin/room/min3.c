// min3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿大廳");
    set_long(@C_LONG
這裡是神殿的大廳，大理石地板上到處聳立著巨大的石柱，石柱上頭密密
麻麻地刻著咒文，似乎是為了封印某種可怕的力量用的。難道這個神殿是用來
鎮壓妖魔用的？ 
C_LONG
    );
    set("exits", ([
	"south" : AREA"min2",
	"north" : AREA"min4",
	"east" : AREA"min3",
	"west" : AREA"min3"
	]) );
    reset();
}

