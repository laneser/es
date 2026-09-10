#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("瀑布");
    set_long(@LONG
在這潺潺的小河上看，只覺得一切都好乾淨，和風徐徐的吹著，天空偶
而有幾隻小鳥吱吱咂咂的飛過，難道這就是所謂的『世外桃源』嗎？北邊是
高大的山壁，西邊有個十分壯觀的瀑布，自上頭衝了下來，形成一道美麗的
彩虹；東邊有一片小沙岸．
LONG
            );
    set("exits",([
        "east":AREA"entrance1",
        "down":AREA"river1",
        "south":AREA"upriver"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

