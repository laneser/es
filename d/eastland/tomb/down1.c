#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地道");
	set_long(
@C_LONG_DESCRIPTION
這兒是一個陰暗的地道，四周是絕對的寂靜，安靜到除了腳步聲外，就只有你自己的心
跳聲。在這種環境中，你唯一想做的事就是趕快往前走，離開這個令人神經緊繃、心跳加速
的地方。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"up" : TOMB"/square9", 
		"down" : TOMB"/down2",  ]) );
	reset();
#include <replace_room.h>		
}

