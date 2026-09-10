#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『迷霧森林』入口");
    set_long(@LONG
山崖的下方竟有一條通道，通道的盡頭似乎是一大片的森林，那兒想必
就是冒險者口中的『迷霧森林』了吧！多年以來，有很多的冒險者對這森林
的一切非常感興趣。魔族的一支在此建國後，便依賴此地的隱密性努力的發
展，不知道目前的森林變的如何了呢！旁邊壁上似乎有些刻字(words)。
LONG
    );
     set("c_item_desc",([
      "words":@LONG
　　　　　　　『此處乃是魔族國境，目前正值戒嚴時期，
　　　　　　　　過往旅客請熟記密碼，以確保國家安全！』
LONG
                      ]) );
    set_outside("island");
    set("exits",([
            "north":AREA"entrance1",
            "east":AREA"gangway2",
            "west":AREA"upriver",
            "south":AREA"entrance2"]) );
     reset();
#include <replace_room.h>
}
