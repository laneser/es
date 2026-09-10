#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("村落");
    set_long(@LONG
『辰馬鎮』是津鳴城內魔族平民居住的一般村落。魔族動工建城前，便
已經確實做好都市規劃，冀望一切建設都能使民族安定繁榮、國家快速發展
。因此所有的建設都以此構想為前提來進行。
LONG
             );
    set("light",1);
    set("exits",([
        "east":CITY"sway2"]) );
    set("objects",([
        "older":TMOB"older",
        "man":TMOB"man",
        "LADY":TMOB"lady"]) );
    reset();
#include <replace_room.h>
}



