#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "企劃室" );
	set_long(
			"這裡是巫師們作企劃的地方，如果你正在作某個企劃，希望其它巫\n"
		"師幫忙或提供意見的，可以在這裡留言( 或者是廣告 )。西邊是巫師的\n"
		"點子中心，往東可以回到巫師辦公室。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"east"	:	"/d/wiz/wiz_office",
		"west"	:	"/d/wiz/ideas"
	]) );

	// Cause the plan_board to load
	call_other( "/d/wiz/plan_board", "???" );
}
