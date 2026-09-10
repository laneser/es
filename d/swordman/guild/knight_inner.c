#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Knight Inner room", "騎士廳");
	set_long( @LONG_DESCRIPTION
This is the inner hall of Knight's guild. Where the important meetings
are held. To the east is the guild.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你現在進入了騎士公會內部的騎士廳，這裡是騎士們開會的地方，只有騎士
公會的人才能進來，大廳中央有一本記載騎士戰功的書(book)，往西走可以回到
騎士公會，而北邊則是騎士們存放高級裝備的儲藏室。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/knight/fortress/knight_storage",
		"south" : "/d/knight/fortress/knight_shop",
		"west" : "/d/knight/fortress/knight_guild" ]) );
	set( "item_func", ([
		"book": "look_book" ]) );
	reset();
}

int look_book()
{
	int ws;

	ws = (int)this_player()->query("war_score");
	if( !ws ) write( "你到目前為止還沒有建立任何戰功。\n" );
	else write( "你目前累積的戰功共有 " + ws + " 點。\n" );

	return 1;
}
