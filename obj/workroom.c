#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "工作室" );
	set_long(
		"這是一間新蓋好的工作室，它目前空蕩蕩地沒有任何東西。也許你第一件\n"
	"要做的就是在這裡加一些東西。\n"
	);
	set( "exits", ([
		"guild" : "/d/wiz/wiz_hall"
	]) );
}
