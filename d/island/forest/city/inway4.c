#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("皇宮大道");
    set_long(@LONG
這是一條完全由石板鋪成的大道，由材質來判斷，應該是取自西方的山
崖，令你不禁想知道當年皇族是如何取材，花了多少人力物力才能建出如此
工整的寬廣大道．
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "east":CITY"garden2",
        "west":CITY"pool",
        "south":CITY"gate5",
        "north":CITY"inway2"]) );
    reset();
#include <replace_room.h>
}