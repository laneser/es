#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("中央大道");
    set_long(@LONG
這是津鳴城內最大的，也是唯一的主要道路，兩旁種滿了大樹，隨著時
光的流逝，樹枝已經向兩旁廣泛的分展開來，如今，已經形成一個完美的天
然隧道了。南邊是一般平民居住的辰馬鎮！
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"r7",
        "west":CITY"r4",
        "south":CITY"sway1",
        "north":CITY"gate5"]) );
    reset();
#include <replace_room.h>
}
