#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "點子中心" );
	set_long(
			"這個地方是讓那些有新點子，但是不知道怎麼將它實作出來，或是\n"
		"沒有時間寫的巫師們提供其它巫師點子的地方。如果這個點子是你自己\n"
		"要做的，請留言在企劃室( 往東走就是 )。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/planning"
	]) );

	// Cause the idea_board to load
	call_other( "/d/wiz/idea_board", "???" );
}
