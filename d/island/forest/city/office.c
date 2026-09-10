#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("將軍府");
    set_long(@LONG
門口佇立著兩隻雄壯威武的石獅子，彷佛在提醒別人不可在此撒野。梁
上掛著寫著『神武將軍府』的橫匾，原來這兒就是總管魔族軍備的軍部。受
封為神武將軍的人可謂「一人之下，萬人之上」，手握強大的兵權，連祭司
都得敬畏三分！
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway3"]) );
    set("objects",([
        "general":TMOB"general"]) );
    reset();
#include <replace_room.h>
}




