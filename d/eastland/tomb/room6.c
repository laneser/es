#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下甬道");
	set_long( 
@C_LONG_DESCRIPTION
這兒是一個長長的甬道，你可以看到前方隱約傳來的亮光。一陣陣的風從前方吹來，
你想大概快到了吧.......
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/square1", 
		"south" : TOMB"/room5",  ]) );
	reset();	
#include <replace_room.h>
}

