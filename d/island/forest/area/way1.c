#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("林間小徑");
    set_long(@LONG
沒想到狹隘的山壁之外，展現在面前的竟是一片寬廣的樹海。這兒的風
和緩多了，不像狹道中那般強勁可怕；四處傳來的是一連串的悅耳鳥鳴，偶
而出現幾聲令人膽寒的低鳴，不知道何處會出現可怕的怪物呢！
LONG
             );
    set("exits",([
            "southwest":AREA"gangway2",
            "east":AREA"way2",
            "north":AREA"way3"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}
