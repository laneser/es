#include "../takeda.h"

inherit ROOM;

void create()
{
	object snake;
	::create();
	set_short( "魔法陣中" );
	set_long(@C_LONG
你進入了這個詭異的魔法陣，魔法陣的中心被層層的黑霧所包圍，不過....
這是霧嗎?你懷疑著,你能很清楚地看到一些懸浮粒子飄散在你的周圍.
\或許是一種邪惡的物質,你能感覺到有著邪惡的成份參雜其中.
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"lair/lair5"
        ]) );
        snake = new(TMONSTER"snake");
        snake->move(this_object());
        reset();
}
int clean_up() { return 0; }
