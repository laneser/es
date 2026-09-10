#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("教場");
    set_long(@LONG
在這寬廣的教場中，只見許多新近入伍的新兵在這兒接受訓練；可見得
魔族是多麼擔心蜥蜴人和武士團會伺機偷襲了。    
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway2"]) );
    set("objects",([
        "soldier#2":TMOB"soldier01",
        "soldier#1":TMOB"soldier01",
        "warrior"  :TMOB"warrior01"]) );
    reset();
#include <replace_room.h>
}
