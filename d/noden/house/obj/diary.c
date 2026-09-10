#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "old diary", "破舊日記" );
	add( "id", ({ "diary" }) );
   set_short( "破舊日記" );
	set_long(
		"這本日記看起來有幾百年的歲月了，你可以讀讀看(read)。\n"
	);
	set( "unit", "本" );
	set( "weight", 5 );
	set( "useless" );
}

void init()
{
	add_action( "do_read", "read" );
}

int do_read(string arg)
{
	if( !arg || !id(arg) ) return 0;
	this_player()->more("/d/noden/house/diary", 0, 1);
	return 1;
}
