#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("『八哩八哩農場』");
    set_long(@LONG
這裡是『八哩八哩農場』，放眼望去看不到任何的土壤，所有的蔬菜都是用
一個小杯子裝著，並且漂浮在空中；上方圍繞著一層魔法壁，用以過濾大氣中的
雜質及防止熱度散失。你對這兒神奇的一切產生極高度的興趣。
LONG
            );
    set_outside("island");
    set("objects",(["farmer":TMOB"farmer"]) );
    set("exits",([
        "west":CITY"farm4",
        "south":CITY"w2"]) );
    reset();
#include <replace_room.h>
}
