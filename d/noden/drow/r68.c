
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("back","神宮後殿");
       set_long(@C_LONG
經過長廊，你現在來到了神宮的後殿，這裡有不少的桌
椅等等的，井然有緒地排列在兩旁，你看到前面的一扇掛畫
中畫有賽亞達的塑像，但是可能是年代久遠吧，已經蒙上了
些灰塵，後殿的天井由一些黑色的大理石雕刻而成，使得四
周看來有股陰涼的氣息。
C_LONG );
       set("exits",([
                     "northwest":"/d/noden/drow/r69",
                     "south":"/d/noden/drow/r67"
                    ]));
       set("light",1);
}

