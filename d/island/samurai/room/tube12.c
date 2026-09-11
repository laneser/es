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
        set( "exits", ([
                "west":MR"tube13",
                "south" :MR"tube08"
                ]) );
         reset();                     
#include <replace_room.h>
}

