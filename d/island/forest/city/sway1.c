#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("石板街");
    set_long(@LONG
這是一條平坦寬廣的大街道，魔族的人利用本身已知的搬運魔法來代替
獸力、人力，因此做出來的路面頗為平坦。兩旁種滿了各式各樣的行道樹，
連在趕路的你，都忍不住想要駐足欣賞隨風搖曳的樹影，好讓自己緊張的心
情得到些微的放鬆。
LONG
);
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"school",
        "west":CITY"hill1",
        "south":CITY"sway2",
        "north":CITY"r6"]) );
        reset();
#include <replace_room.h>
}