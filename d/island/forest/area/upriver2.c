#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("河流");
    set_long(@LONG
在這潺潺的小河上看，只覺得一切都好乾淨，和風徐徐的吹著，天空偶
而有幾隻小鳥吱吱咂咂的飛過，難道這就是所謂的『世外桃源』嗎？南面和
西面都是高聳的山壁，令你不解的是：這河流怎麼沒出口了還會流？東邊的
沙岸上長著一棵非常茂密的大樹！
LONG
            );
    set("exits",([
        "east":AREA"entrance2",
        "down":AREA"river2",
        "north":AREA"upriver"]) );
    set_outside("island");
    reset();
#include <replace_room.h>
}

