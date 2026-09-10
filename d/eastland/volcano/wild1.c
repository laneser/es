#include "oldcat.h"

inherit ROOM;

void create()
{
::create();
set_short("綠林");
set_long( 
@LONG_DESCRIPTION
你站在一片綠色樹林的小徑中，這片欣欣向榮的樹林，使你有陶醉在大自然的
感覺，在這茂密的樹林之中，你還可以聽到鳥鳴聲，間些傳來一陣不知蟲名發出的
聲音，這條小徑不知道會通向何處。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest": "/d/eastland/5,1.east",
     "east" : ONEW"wild2", ]) );
set( "objects", ([
     "ohio":OMONSTER"ohio" 
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
