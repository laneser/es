// min5.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿內廳");
    set_long(@C_LONG
你現在在神殿的內廳裡，四周一片空空湯湯，只有素淨的牆壁和天
花板靜靜地立著。凜冽的寒風由四面八方吹來，令你覺得有些寒冷。「
哪來的這麼大風？」你的心中不由得納悶著。  
C_LONG
    );
    set("exits", ([
	"north" : AREA"min6",
	"south" : AREA"min4"
	]) );
    reset();
}

