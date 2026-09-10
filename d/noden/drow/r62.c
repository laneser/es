#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("coldtune","寒冷的石階");
       set_long(@C_LONG
這條幽長的石階不知延伸到何處，但是由於四壁上仍插
有火把，看起來並不會令人感到害怕，但是由於越來越冷的
環境，令你忍不住打了個寒顫。
C_LONG );
       set("exits",([
                     "northup":"/d/noden/drow/r63",
                     "southdown":"/d/noden/drow/r61"
                    ]));
       set("light",1);
}
