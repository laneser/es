#include <../tower.h>

inherit ROOM;

void create()
{
	::create();
//	if ( !ob ) return ;
	set_short("惡魔塔內");
	set_long( @C_LONG_DESCRIPTION
這裡是惡魔塔的第二個房間.
C_LONG_DESCRIPTION
	);
	set( "exits", ([ 
		"south" : TOWER_F1"room1", 
//		"north" : TOWER_F1"room1",
	]) );
/*
	ob->set("objects",([
		"orc" : MOB"orc",
		]) );
*/
	reset();
replace_program(ROOM);
}
