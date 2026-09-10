#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("樹林");
	set_long( @C_LONG_DESCRIPTION
這裡原本是美好的樹林，現在卻被破壞的亂七八糟，樹木傾倒的聲音還不斷
的傳來，你不禁氣的七竅生煙，惋惜這份天然美景。
C_LONG_DESCRIPTION
	);
    set("objects",([ "elephant" : SAULIN_MONSTER"elephant" ]) );
        set_outside("eastland");
	set( "exits", ([
		 "south" : SAULIN"small_path2",
	]) );
	reset();	
#include <replace_room.h>
}
