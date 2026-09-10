#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("石階小徑");
	set_long( @C_LONG_DESCRIPTION
你走在少林寺內千廊百院間的通道上，磨損得圓潤光華的石階無言的對你
誇耀少林寺的悠久歷史。遙望寺外蓊鬱松林，寺內黃瓦朱牆，寺僧來去、遊客
相接，你不禁有出世之想。東邊就是鼎鼎有名的達摩面壁處。
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
    set( "pre_exit_func", ([
    	"east" : "check_monk"
    ]) );
    set( "objects", ([
    	"monk1" : SAULIN_MONSTER"monk",
    	"monk2" : SAULIN_MONSTER"monk",
    ]) );
	set( "exits", ([
		 "east"  : SAULIN"damo_stone",
		 "west"  : SAULIN"entrance"
	]) );
	set("no_monster", 1);
	reset();
}

int check_monk()
{
	if( wizardp(this_player()) || !present("monk") ) return 0;
	tell_object(this_player(),
		"達摩堂 黑衣和尚說: 那裡乃本寺聖地, 遊客請止步。\n"
	);
	return 1;
}
