// File: /d/noden/asterism/path31.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("小徑");
	set_long(
		@C_LONG_DESCRIPTION
你現在正漫步在一片樹林中。四周的蟬鳴鳥聲使你幾乎想要永遠住在這人間仙境,
不再回到那紛擾的世界。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
//	set( "light", 1 );
	set( "exits", ([
	        "east" : ASTR"path3",
		]) );
        set("objects",([
                "monkey#1" : MOB"monkey" ,     
                "monkey#2" : MOB"monkey" ,     
                ]) ) ;
	reset();
#include "replace_room.h"
}
