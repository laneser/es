#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("井底");
	set_long( @LONG
這裡是一口枯井底。這口井因為年久以來水源已斷，不堪使用，上面陽光照射
不到，以致於牆壁多生青苔，底部是一堆爛泥。好在還留有以前人家使用的連接水
桶的繩子，你可以試著往上爬去。
LONG
	);
	set( "exits", ([ 
           "up" : SCITY"wn2"
        ]) );
        set( "objects", ([
          "objects":SWMOB"dog1"
        ]) );
	reset();
}
