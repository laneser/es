// lib1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．長廊");
    set_long(@C_LONG
你現在身處於一條長長的走廊上，大理石鋪成的走道向東方延伸。西方是一
面神奇的魔法壁，可以清楚地看見大廳內的情形。長廊的牆壁不知是用什麼東西
所建造的，閃耀著淡淡的光芒。
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib0",
	"east" : AREA"lib2"
	]) );
    set("light", 1);
    reset();
}


