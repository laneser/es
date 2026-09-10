
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("iceroom","寒冷的洞穴");
       set_long(@C_LONG
經過了冗長的階梯，你來到了一個寒冷的洞穴，四周都
結了一層薄薄的冰霜，更使你感到不快；你看到洞穴的北端
有扇大石門牢牢的鎖著，而且似乎有幾個人影在那晃動。
C_LONG );
       set("exits",([
                     "north":"/d/noden/drow/r64",
                     "southdown":"/d/noden/drow/r62"
                    ]));
       set("object",([
                      "guard":"/d/noden/drow/mob/m29",
                      "ghost":"/d/noden/drow/mob/m23"
                   ]));
}
