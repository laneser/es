#include "almuhara.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("地下通道");
	set_long( 
@C_LONG_DESCRIPTION
這兒是一個陰暗的通道，四周極其地安靜，你幾乎可以聽到自己的心跳和腳步聲相呼應
著。由前方傳來的寒意令你冷的直打哆嗦，這是以往從未曾有過的感覺，你不禁猶豫起來，
到底該不該繼續往前走呢??
C_LONG_DESCRIPTION
	);
	
	set( "exits", ([ 
		"east"  : TOMB"/sword2",
		"west"  : TOMB"/sword4"  ]) );
	create_door( "west","east",
		   (["keyword" : ({"door", "iron"}),
		     "name"    : "iron door",
		     "c_name"  : "大鐵門",
		     "desc"    : "A huge iron door\n",
		     "c_desc"  : "一扇堅固的大鐵門。\n",		
		     "lock"    : "TOMBKEY_2",
		     "status"  : "locked",
		     ]) );		
	reset();	
}

