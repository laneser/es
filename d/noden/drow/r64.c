
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("front","前庭廣場");
       set_long(@C_LONG
這裡空氣清新，你聞到一股淡淡的木菰氣味，四周寬廣
並有水聲潺潺，你注意到前方有一座大宮殿，但由一於地勢
較高，你必需從側面的小徑繞至宮庭側殿再進入大宮庭，東
邊則有一扇開啟的石門，黝黑的地道不知通往何處。
C_LONG );
       set("exits",([
                     "northwest":"/d/noden/drow/r65",
                     "eastdown":"/d/noden/drow/r71",
                    ]));
       set("pre_exit_func",([
                     "eastdown":"check_knight"]));
       set("light",1);
       set("object",([
                      "skeleton":"/d/noden/drow/mob/m30",
                   ]));
}
