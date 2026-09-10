#include <mudlib.h>

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
	
	set("light", 1);
	set_short( "長廊" );
	set_long( @LONG
這是一條寬敞的地下走廊，裡面空蕩蕩的。
LONG
	);

	set("exits", ([
		"up" : "/d/thief/hall/thief_guild",
//		"south" : "/d/thief/hall/backstab_room2",
	]) );
	reset();
}

