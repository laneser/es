#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "十字路口" );
   set_long(@ANGEL
你走在一個十字路口上，左右個有一條小路通向碉堡，而南北接向亞瑟斯路，
你可以看到北方有著一個高大建築．
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard",
	        "guard2":MOB"guard",
	        ]) );
        set( "exits", ([
    "west"  :MR"road2",
    "east"  :MR"road1",
    "south" :MR"cac01",
    "north" :MR"cac03"
                ]) );
         reset();                     
#include <replace_room.h>
}

