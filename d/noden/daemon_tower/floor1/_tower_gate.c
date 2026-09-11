#include "../tower.h"
void create(object ob)
{
	if (!ob) return;
	ob->set_short("惡魔塔大門");
	ob->set_long( @C_LONG_DESCRIPTION
這裡是惡魔塔的大門.
C_LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/u/r/ruby/rooms/workroom", 
		"north" : TOWER_F1"room1",
	]) );
	ob->reset();
}
