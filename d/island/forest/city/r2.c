#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("中央大道");
    set_long(@LONG
這是津鳴城內最大的，也是唯一的主要道路，兩旁種滿了大樹，隨著時
光的流逝，樹枝已經向兩旁廣泛的分展開來，如今，已經形成一個完美的天
然隧道了。
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"gate4",
        "south":CITY"r4",
        "north":CITY"gate3"]) );
    reset();
#include <replace_room.h>
}