
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The road of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村莊的環莊道路上,這裡有著非常和平安詳的氣氛,恍佛是一個世
外桃源.這裡已經多年沒有戰爭了,矮人們的童年幾乎在此渡過.
CLong
    );
    set("exits",([
                "north":Deathland"/village/v12",
                "east":Deathland"/village/v21",
             ]));
    set("objects",([
        "child":Monster"/child",
                  ]) );
    ::reset();
#include "../replace_room.h"
}
