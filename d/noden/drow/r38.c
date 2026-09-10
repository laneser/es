#include "iigima.h"

inherit ROOM;

void create()
{

        ::create();
        set_short( "stone floor","地下石階");
        set_long(

@C_LONG
這裡是一處冗長的石階，蜿蜒向下，你看不到石階的盡頭，牆上微弱
的火把還在閃爍著，但是好像快熄滅了，階梯溼漉漉的，長有不少青苔，
你要小心步行，千萬別滑倒了。
C_LONG
        );
        set( "light",1 );
        set( "exits", ([           
                     "southeast": DROW"r39",
                    "north":DROW"r28"
        ]) );
}
