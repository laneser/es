#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "青石小徑" );
   set_long(@ANGEL
你走在一個青石小徑上，路面明顯的比原來那條大道小很多，而且路面也改由青石
來鋪成，沿著路走下去可以通往碉堡．    
ANGEL
   
         );
	set( "light",1);	
	set_outside("eastland");	
        set( "exits", ([
     "east" :MR"ca1",
     "west" :MR"road1",
                ]) );
         reset();                     
#include <replace_room.h>
}

