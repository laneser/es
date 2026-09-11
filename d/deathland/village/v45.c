
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The entrance of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村莊的環莊道路上,這裡有著非常和平安詳的氣氛,恍佛是一個世
外桃源.這裡已經多年沒有戰爭了,矮人們的童年幾乎在此渡過.北邊是矮人的育嬰室,大
部份的矮人都是在此地出生的
CLong
    );
    set("exits",([
                "west":Deathland"/village/v35",
                "north":Deathland"/village/vr5",
                "east":Deathland"/village/v55",
             ]));
    ::reset();
#include "../replace_room.h"
}
