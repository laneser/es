#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓");
	set_long( 
@C_LONG_DESCRIPTION
你終於進到傳說中的陵墓了 !! 你簡直不敢相信你所看到的景象。在你頭頂上竟是一片
璀璨的星空，眾星們是用金鋼鑽做的，而一輪明月則是一塊皎潔無瑕的碧玉，冷冷的銀光自
星空灑下。在你面前躺著的竟是縮小版的東方大陸 !! 地形山川、樹木建築無不維妙維肖，
河流中甚至還有水在緩緩流動著，真是太驚人了，不知道前人是如何創造出這般景象，委實
令人敬佩。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/gate",
		"east"  : TOMB"/inner2",
		"west"  : TOMB"/inner8"  ]) );
	reset();	
#include <replace_room.h>
}

