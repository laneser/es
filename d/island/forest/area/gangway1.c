#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("山間狹道");
    set_long(@LONG
這是一條狹窄的通道，兩旁是高聳的山壁，似乎隨時會有落石崩下來一樣，
不時傳來不明的怪叫聲，令人不寒而顫。
LONG
            );
    set("exits",([
            "west":AREA"entrance",
            "east":AREA"gangway2"]) );
    set_outside("island");
     reset();
}
