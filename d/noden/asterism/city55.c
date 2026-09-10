// File: /d/noden/asterism/city55.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("城市大路");
	set_long( 
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城的大道路,由於半身人靈巧的設計天份及矮人的
建築技巧,這裡的道路十分寬敞筆直,而且道路兩旁種植的樹木花草在相互搭配之下,
讓人好像置身於一座優美的公園。在東邊有一座高塔(tower) ,上面有著一面象徵著
半身人的旗子.西邊是很堅固的城牆,經過數百年的風吹日曬,依然屹立不搖。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set("c_item_desc",([
	    "tower":"一座建築的很宏偉的高塔.\n"
	    ]) );
	set( "exits", ([ 
		"south" : ASTR"city56",
		"north" : ASTR"city54",
		]) );
	reset();
}

void init()
{
   add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str||str!="tower") return 0;
    write("你進入了塔中.\n");
    this_player()->move_player(ASTR"tower1-1",
               "%s進入了塔中.\n","%s從外面進來.\n");
     return 1;
}
