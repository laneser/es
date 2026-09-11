#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "地下水道" );
   set_long(@ANGEL
你來到一個地下水道，雖然是在地下，但空氣卻是很清新，讓你不會
有氣悶的感覺，而且你發現這裡地上蠻乾淨的，似乎有人居住在裡面．    
ANGEL
   
         );
         
	set( "light",0);
	set("objects",([
	"rat1":MOB"big_rat",
	"rat2":MOB"big_rat"
	             ]));
        set( "exits", ([
                "south":MR"tube07",
                "north" :MR"tube12",
                "east" :MR"tube09"
                
                ]) );
         reset();                     
#include <replace_room.h>
}

