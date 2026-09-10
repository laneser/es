// min0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿入口");
    set_long(@C_LONG
這裡是個神殿的入口，四周冷冷清清地，不但沒有莊嚴神聖的氣氛，反倒
令人覺得有些陰森恐怖。從這裡往神殿裡看去，盡是一片黑暗，看來如果想要
找到出口的話，只有硬著頭皮往前走了。
C_LONG
    );
    set("exits", ([ "north" : AREA"min1" ]) );
    reset();
}


