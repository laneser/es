#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "忍者屋" );
   set_long(@ANGEL
你來到一個忍者屋，你現在終於知道是什麼人住在地下了，原來是武士城堡
的另一之部隊忍者們住在下面，因為是在地下，所牆壁上有好幾顆夜明珠擺著用
來照明，而旁邊放了幾個當作練習靶的假人，還有一陣微風吹著，你可以確定附
近一定有出口．    
ANGEL
   
         );
         
	set( "light",1);
	set("objects",([
	"nei1":MOB"nei"
	             ]));
        set( "exits", ([
                "north":MR"tube10",
                "south" :MR"ca1"
                ]) );
         reset();                     
}

