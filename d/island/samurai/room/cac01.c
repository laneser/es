#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "亞瑟斯路" );
   set_long(@ANGEL
你走在亞瑟斯路上，這是一個寬廣的大路，其路面是用堅硬的花崗石做的，而
道路的兩旁各有一個像是碉堡一個的建築，而這條道路向北延伸．    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
                "south"  :MR"cac00",
                "north" :MR"cac02",
                ]) );
         reset();                     
#include <replace_room.h>
}

