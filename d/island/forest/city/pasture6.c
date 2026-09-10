#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『咖哩咖哩牧場』的乳品收集廠");
    set_long(@LONG
這裡是『咖哩咖哩牧場』的乳品收集廠，場內到處充斥著奇形怪狀的儀
器；只有少量的半人馬工人在這裡工作，因為所有的控制都是魔族利用奧妙
的古魔法在控制著。因此當你進到這個工廠時，可以明顯的感到有一股不可
思議的能源，正在你的周圍不斷的流動。
LONG
            );
    set("light",1);
    set("exits",(["north":CITY"pasture3"]) );
    set("objects",([
        "cow#2":TMOB"milker",
        "cow#1":TMOB"milker",
        "worker#2":TMOB"worker",
        "worker#1":TMOB"worker"]) );    
    reset();
#include <replace_room.h>
}
