#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("灌木叢");
	set_long( 
@LONG_DESCRIPTION
你站在這片灌木叢中的小徑上，樹木的高度大約和你的身高差不多，以你的常
識判斷，可能這個地區的水資源並不是那麼豐富，這條小徑湮沒在這參差不齊的灌
木叢之中，你發現在你旁邊的地上有一灘血的遺蹟，你猜你可能已經在獵頭族的勢
力範圍內了，你還看到有一隻小兔子躲在灌木叢裡看著你。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "east" : ONEW"wild10",
     "northwest" : ONEW"wild7",
     "southwest" : ONEW"wild4", ]) );
set( "objects", ([
     "whunter":OMONSTER"whunter",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
