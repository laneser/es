#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("洞窟");
    set_long(@LONG
這兒黑黑窄窄的，又充滿的噁心撲鼻的臭騷味，真是令人渾身不舒服；
仔細一聽，似乎有動物的呼吸聲，是什麼動物的巢穴嗎？哇～～～！原來是
魔狼的窩!!
LONG
             );
    set("exits",([
            "north":AREA"hole2"]) );
    set("objects",([
         "wolf":TMOB"wolf"]) );
    reset();
#include <replace_room.h>
}
