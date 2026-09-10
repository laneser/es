#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("產業道路");
    set_long(@LONG
這是一條鋪滿石板的產業大道，也是平時『津鳴城』對外聯絡的唯一途
徑。兩旁有籬笆樹立著，藉以分隔道路和農田，避免因為人畜的不小心踐踏
而損壞了寶貴的農作物；北邊是『八哩八哩農場』的入口。
LONG
            );
    set_outside("island");
    set("exits",([
        "east":CITY"w3",
        "west":CITY"w1",
        "north":CITY"farm5"]) );
    reset();
#include <replace_room.h>
}
