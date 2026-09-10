#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『咖哩咖哩牧場』");
    set_long(@LONG
這裡是『咖哩咖哩牧場』，也是魔族及半人馬族乳品食物的主要供應場
所；在這裡工作的主要都是半人馬工人，畜養的大多是經過精選的優良牛隻
，在魔族不斷的改進畜養技術，及半人馬們細心的照顧之下，每天都能生產
大量的鮮乳以供飲用和加工。
LONG
            );
    set_outside("island");
    set("exits",([
        "south":CITY"pasture6",
        "north":CITY"w3"]) );
    reset();
#include <replace_room.h>
}
