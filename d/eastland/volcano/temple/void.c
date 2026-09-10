#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "The Void", "一片虛無" );
	set_long("你放眼望去，四周盡是白茫茫的一片，看不到邊境，難到這真的是神的世界嗎 ? \n");
        set("exits",([
            "east":OTEMP"void",
            "west":OTEMP"void",
            "north":OTEMP"void",
            "south":OTEMP"void",
            ]) );
	set("light", 1);
}
