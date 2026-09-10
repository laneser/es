#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("星河");
    set_long(@LONG
你身處於一片浩瀚的星河中，四周佈滿了一閃一閃的小星星，好像
是在對你招手似的！往下一看，只見到三塊獨立的大陸，中間夾了個小
小的島嶼，原來東方故事中的版圖是這樣的啊！待在這裡的感覺是挺不
錯的，只是．．該怎麼下去呢？
LONG
            );
    set("light",1);
    set("exits",(["northup":CITY"garden2"]) );
    set("exit_suppress",({"northup"}) );
    reset();
#include <replace_room.h>
}    