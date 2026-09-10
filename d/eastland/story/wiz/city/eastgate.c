#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("「巫咸國」東門");
	set_long( @LONG
這裡是「巫咸國」的東門，城門兩旁聳立著高牆，牆底則是佈滿青苔的基石，
另外在城樓上還刻著「巫咸國」三個漆金大字。城牆上，衛兵輪流交替，個個雄糾
糾氣昂昂，威武挺拔，正在捍衛著「巫咸國」的安全。由這裡往西則進入城中。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ee",
            "east" : SCITY"plain1",
        ]) );
        set("objects", ([
            "guard#1" : SWMOB"wiz_guard1",
            "guard#2" : SWMOB"wiz_guard1",
        ]) );
	reset();
}
