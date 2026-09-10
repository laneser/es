//#pragma save_binary

#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("微風路");
	set_long( @LONG_DESCRIPTION
你現在正走在微風路上。廣場位於你的西方不遠處，微風路向東
一路延伸下去，北邊的建築物是本鎮唯一的書店，南邊則是一棟奇怪
的建築，似乎不斷地散發著強烈的魔法。
LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
        "north" : "/d/noden/farwind/bookshop",
		"east" : "/d/noden/farwind/bazz3",
		"west" : "/d/noden/farwind/bazz1",
	        "south" : "/d/noden/farwind/auc_room",
	]) );
    create_door("north","south",
    	 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木門",
		     "c_desc"  : "這是一扇可愛的小木門，門上掛了一個書店的招牌",		
		     "status"  : "open",
		]) );
    reset();
}
