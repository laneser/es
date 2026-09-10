
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("garden","神宮後庭花園");
       set_long(@C_LONG
這個大約跟神殿同大小的花園種滿了各式各樣的奇異花
卉，你看到西邊有一個小湖，上面還有個小島，也種了各種
不同的植物，似乎有人在這邊打掃，庭園的盡頭有一扇門，
不過鎖得緊緊的，看來是不能打開了。
C_LONG );
       set("exits",([
                     "southeast":"/d/noden/drow/r68"
                    ]));
       set("light",1);
       set("object",([
                      "linna":"/d/noden/drow/mob/m28"
                   ]));
}
