#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("秘道");
	set_long( 
@LONG_DESCRIPTION
你正在一個黑黝黝的秘道中，你感覺到一絲冷意，你看到一隻小老鼠在角落正在發
抖，以你的第六感可以感覺到再往前走去，可能會有危險。
LONG_DESCRIPTION
	);
set( "exits", ([
     "up" : OGROUP"warea9",
     "west" : OGROUP"tunnel2"
     ]) );
reset();
}
void init()
{
     if(this_player()) this_player()->set_explore("eastland#38");
}
