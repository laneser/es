#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("洞窟");
    set_long(@LONG
這兒黑黑窄窄的，又充滿的噁心撲鼻的臭騷味，真是令人渾身不舒服；
仔細一聽，似乎有動物的呼吸聲，是什麼動物的巢穴嗎?
LONG
             );
    set("exits",([
            "south":AREA"hole3",
            "north":AREA"hole1"]) );
    set("objects",([
         "s_wolf#2":TMOB"s_wolf",
         "s_wolf#1":TMOB"s_wolf"]) );    
    reset();
#include <replace_room.h>
}
