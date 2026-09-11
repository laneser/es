#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "兵營" );
	set_long(
	"這裡是梁山泊的部隊休息室，如果強盜們沒有排到偵察或防禦的任務時，\n"
	"這裡就是他們過夜休息的地方，如果沒有特殊事情的話，部隊的指揮官也\n"
	"會在這裡休息，直到換防或輪休。\n"
	);
	set( "light",1 );
        set( "exits", ([
                "south"  : TROOM"plaza4",    
        ]) );
        set( "objects",(["bandit":TMONSTER"small_bandit",
             "shu":TMONSTER"shu"]));
        reset();
}
int clean_up() { return 0; }