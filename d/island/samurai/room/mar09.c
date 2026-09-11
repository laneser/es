#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "旅店" );
   set_long(@ANGEL
這裡是一間不起眼的旅店，昏暗的燈光和老舊的傢俱，讓你懷疑
這種店怎麼會有人來住．　
ANGEL

   
         );
	set( "light",1);		
	set( "objects",([
	"fan":MOB"fan"
	]));
        set( "exits", ([
    "up":MR"mar10",    
    "south" :MR"mar08"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

