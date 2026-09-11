#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "upstair of Chung Yi Hall", "忠義廳樓上" );
	set_long(
	"這是一間小小的房間，佈置的很像靈堂的樣子，一張香案擺在正中，供的\n"
	"正是前代首領托塔天王晁蓋，上面插了幾隻香燭，正靜靜的燃燒，香灰輕輕\n"
	"的落下，令人頓悟世事之無常。\n"
	);
        set( "exits", ([
                "down" : TROOM"hall"
        
        ]) );
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
                "wizard":TMONSTER"wizard"
        ]) );        
        reset();
}
int clean_up() { return 0; }