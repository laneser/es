#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下通道");
	set_long( 
@C_LONG_DESCRIPTION
這兒是一個陰暗的通道，四周極其地安靜，你幾乎可以聽到自己的心跳和腳步聲相呼應
著。由前方傳來的寒意越來越重，這是以往從未曾有過的感覺，你不禁猶豫起來，到底該不
該繼續往前走呢??
C_LONG_DESCRIPTION
	);
	
	set( "exits", ([ 
		"east"  : TOMB"/sword1",
		"west"  : TOMB"/sword3"  ]) );
	reset();
#include <replace_room.h>
}

