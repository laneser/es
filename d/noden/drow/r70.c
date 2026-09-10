
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("tune2","寧靜石道");
       set_long(@C_LONG
這條傾斜的石道斜斜的向前延申，不知道盡頭在何處，
石牆上，每隔幾步便插了一根火把，你不會因此而迷失了方
向，甬道內靜得出奇，沒有絲毫聲響，路的盡頭彷佛找不著
似的，你仍要小心地前進。
C_LONG );
       set("exits",([
                     "northdown":"/d/noden/drow/r60",
                     "southup":"/d/noden/drow/r70"
                    ]));
       set("light",1);

}
