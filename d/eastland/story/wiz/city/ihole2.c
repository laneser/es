#include "../../story.h"

inherit ROOM;
void create()
{
        ::create();
	set_short("聖池");
	set_long( @LONG
這裡就是傳說中的聖池，孕育著聖水－「天堂之水」。其實，這裡的「天堂之
水」並非真正的液體，乃是一種氣體，需要經過凝結之後才會成為真水。大祗天生
靈物必有神獸呵護，想必你已經歷過了在聖池的周圍潛伏著的一隻千年寒冰精魂修
練而成的妖物的考驗。
LONG
	);
        set("exits",([
          "south":SCITY"ihole1"
        ]) );
        set("heaven_water",1); 
	reset();
}
