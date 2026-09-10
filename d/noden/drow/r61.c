
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("tuen2","寧靜石道");
       set_long(@C_LONG
經過了冗長的步行後，你到了石道的盡頭，這邊感覺稍
為寒冷，令你不禁打了個寒顫，前面有個石階，不知會通往
何處？你注意到在腳邊，有不少的毛皮與枯樹根散落一地，
看來似乎有生物的蹤跡。
C_LONG);
       set("exits",([
                     "northup":"/d/noden/drow/r62",
                     "southup":"/d/noden/drow/r60"
                    ]));
       set("light",1);
       set("object",([
                      "rat":"/d/noden/drow/mob/m22 "
                   ]));

}
