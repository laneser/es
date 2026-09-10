// eda2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依達波第亞宮．宮門");
    set_long(@C_LONG
這裡是依達波第亞宮的宮門，門楹上嵌著一顆斗大的水晶，隱隱約約地發
出一些黯淡的光芒，襯著那搖搖欲墜的石柱和基石，這地方想必也已然荒廢了
一段很長的時間了。
C_LONG
    );
    set("exits", ([ "north" : AREA"eda3" ]) );
    reset();
}

