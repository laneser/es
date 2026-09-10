// File: /d/noden/asterism/city_entrance.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("城門入口");
	set_long( 
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城的入口, 高聳的城牆石壁, 精緻的鑲壁雕像,
每一個細節都顯示出這個城的不平凡。 三根巨大的旗子飄揚在城門上頭, 代表著
三族和平共處的象徵。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"down" : ASTR"ladder03",
		"east" : ASTR"city54", 
		]) );
	reset();
#include "replace_room.h"
}
