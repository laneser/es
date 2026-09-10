#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("樹林");
    set_long(@LONG
這兒四周長滿了奇形怪狀的植物，大多是目前尚不為人知的。風也已經
和緩多了，不像狹道中那般強勁可怕；四處傳來的是一連串的悅耳鳥鳴，偶
而出現幾聲令人膽寒的低鳴，不知道何處會出現可怕的怪物呢！
LONG
             );
    set("exits",([
            "west":AREA"way16",
            "north":AREA"way17"]) );
    set_outside("island");
    set("objects",([
         "hawk":TMOB"hawk"]) );
    reset();
#include <replace_room.h>
}

