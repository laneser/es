#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下石室");
	set_long( 
@C_LONG_DESCRIPTION
你進入了一個不大的石室，四周的牆壁是用上好石磚砌成的。一些像是祭祀的用品整齊
地擺在這兒，只是看來已經很久沒有人動過這些東西了。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west" : TOMB"/room1",  ]) );
	reset();	
#include <replace_room.h>
}

