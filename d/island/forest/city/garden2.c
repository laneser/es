#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大草坪");
    set_long(@LONG
這而是皇宮內唯一的大草坪，平時王族的小孩子就在這兒嬉戲遊玩，遙
照天皇偶而也會這兒和大臣們商討國事；不過最主要的用途是拿來當作習武
的場所。
LONG
             );
    set_outside("island");
    set("exits",([
        "west":CITY"inway4",
        "north":CITY"inway3"]) );
    set("light",1);
    set("objects",([
        "oldman":TMOB"leaderii",
        "prince":TMOB"tanki"]) );
    reset();
#include <replace_room.h>
}

