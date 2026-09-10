#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("皇宮大殿入口");
	set_long( @LONG
你來到「巫咸城」人民的精神象徵皇宮裡面。在你兩旁各站著兩個精神抖擻的
殿前禁衛，是負責宣詔外人覲見的。前面翡玉白階鑲著碗大的珍珠，前面不遠處是
城主和文武官員討論事情的地方，那裡金光閃閃刺眼已極！
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "north" : SCITY"palace3",
              "out" : SCITY"palace1"
        ]) );
	reset();
}
