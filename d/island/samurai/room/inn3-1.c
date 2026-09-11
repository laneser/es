#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓三樓" );
   set_long(@ANGEL
在你來到千川樓三樓，這千川樓最高的地方，同時也是武士團隊長約修的住
所，但也是最安靜的地方，在這裡你找不到任何一個守衛，似乎約修對於下面兩
樓的守衛相當有自信，空氣中還飄有一股黑檀木的香氣．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "down"  :MR"inn2-6",    
    "north" :MR"inn3-2",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

