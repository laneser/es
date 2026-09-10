#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("東大街");
	set_long( @LONG
你走正走在「巫咸城」內東大街上，大街往北邊方向延伸，可容納三匹馬並行
的寬度，南邊則是南大街。東大街的地是用大理石鋪成的，整理的很乾淨。自從主
大道封閉已後，東大街變成了城中最熱鬧的地方，原因無他，因為許多重要的鋪子
都在這條東大街上。這裡兩旁都是一排排的商店，在西邊有一家可說是城內最大的
一間商店。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	   "south" : SCITY"se",
       	   "north" : SCITY"ee",
            "west" : SCITY"store",
        ]) );
        set( "objects", ([
                "soothsayer":SWMOB"soothsayer1",
        ]) );
        reset();
}
