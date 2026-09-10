#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("產業道路");
    set_long(@LONG
這是一條鋪滿石板的產業大道，也是平時『津鳴城』對外聯絡的唯一途徑
。兩旁有籬笆樹立著，藉以分隔道路和農田，避免因為人畜的不小心踐踏而損
壞了寶貴的農作物；南邊是『咖哩咖哩牧場』的入口，東邊是津鳴城西門。
LONG
            );
    set_outside("island");
    set("exits",([
        "east":CITY"gate1",
        "west":CITY"w2",
        "south":CITY"pasture3"]) );
    reset();
#include <replace_room.h>
}
