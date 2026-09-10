//#pragma save_binary

#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("微風路");
	set_long( @C_LONG_DESCRIPTION
你現在正走在微風路上。廣場位於你的西方不遠處，微風路向東
一路延伸下去，北邊的建築物是本鎮唯一的酒吧。
C_LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
		"north" : "/d/noden/farwind/wineshop",
		"east" : "/d/noden/farwind/bazz2",
		"west" : "/d/noden/farwind/square",
		"south" : "/d/noden/farwind/hocker.c"
	]) );
    create_door("north","south",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "木門",
		     "c_desc"  : "這是一扇可愛的小木門，門上掛了一個酒店的招牌。\n",		
		     "status"  : "open"
		]) );
   reset();

}
