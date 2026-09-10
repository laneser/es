// File: /d/noden/asterism/city14.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("A city road", "城市大路");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城的大道路的盡頭,由於半身人靈巧的
設計天份及矮人的建築技巧 ,這裡的道路十分寬敞筆直,而且道路的兩旁
種植的樹木花草在相互搭配之下,讓人好像置身於一座優美的公園 .東邊
是很堅固的城牆,在數百年的風吹日曬之下,依然屹立不搖.南邊有一座高
塔(tower),上面插著矮人王阿萊特斯的旗子. 西南方有一條綠意盎然的小
徑,似乎通往一處優靜的地方。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
	    "tower":"一座建築的很宏偉的高塔.\n"
	    ]) );
	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north":ASTR"city13",
		"southwest":ASTR"path1"
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
    this_player()->move_player(ASTR"tower2-1",({
               "%s進入了塔中.\n","%s從外面進來.\n",}),"");
     return 1;
}
