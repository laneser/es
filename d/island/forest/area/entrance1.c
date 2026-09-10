#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Beach","河濱");
    set_long(@LONG
展現在眼前的是一片高聳的山壁，平時由遠處就能看得見，旁邊還有一
條清澈的小河流，大概是因為人煙稀少的關係，這條小河還得以維持原來的
風貌。
LONG
             );
    set("exits",([
            "south":AREA"entrance",
            "west":AREA"upriver1"]) );
    set_outside("island");
     reset();
#include <replace_room.h>
}
