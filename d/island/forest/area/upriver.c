#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("河流");
    set_long(@LONG
在這潺潺的小河上看，只覺得一切都好乾淨，和風徐徐的吹著，天空偶
而有幾隻小鳥吱吱咂咂的飛過，難道這就是所謂的『世外桃源』嗎？
LONG
            );
    set("exits",([
        "east":AREA"entrance",
        "down":AREA"river",
        "north":AREA"upriver1",
        "south":AREA"upriver2"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

