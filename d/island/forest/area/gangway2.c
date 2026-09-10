#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("山間狹道");
    set_long(@LONG
這是一條狹窄的通道，兩旁是高聳的山壁，似乎隨時會有落石崩下來一樣，
不時傳來不明的怪叫聲，令人不寒而顫。東邊似乎有座城！
LONG
            );
    set("exits",([
            "east":CITY"w1",
            "west":AREA"entrance",
            "northeast":AREA"way1",
            "southeast":AREA"way12"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
