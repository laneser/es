#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓");
	set_long( 
@C_LONG_DESCRIPTION
這兒就是傳說中的陵墓了，在你頭頂上竟是一片璀璨的星空，眾星們是用金鋼鑽做的，
而一輪明月則是一塊皎潔無瑕的碧玉，冷冷的銀光自星空灑下。在你東邊躺著的是縮小版的
東方大陸 !! 地形山川、樹木建築無不維妙維肖，河流中甚至還有水在緩緩流動著，真是太
驚人了，不知道前人是如何創造出這般景象，委實令人敬佩。西邊則是一面純白色的牆壁，
找不出一點汙跡。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"north"  : TOMB"/inner6",
		"south"  : TOMB"/inner8"  ]) );
	reset();	
#include <replace_room.h>
}

