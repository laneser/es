#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("東大街");
	set_long( @LONG
你走正走在「巫咸城」內東大街上，大街往南邊方向延伸，可容納三匹馬並行
的寬度，北邊則是北大街。東大街的地是用大理石鋪成的，整理的很乾淨。自從主
大道封閉以後，東大街儼然變成了城中最熱門的地帶，原因無他，因為許多重要的
鋪子都在這條東大街上，這裡更尤於接近城中心道路，平時人潮攜來我往，好不熱
鬧。西邊是城中心道路可通往皇宮，東邊則是一排排的商店。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ne1",
       	   "south" : SCITY"ee",
       	   "north" : SCITY"en2"
        ]) );
        set("objects", ([
               "vendor" : SWMOB"vendor1",
           "merchant#1" : SWMOB"merchant1",
           "merchant#2" : SWMOB"merchant2",
        ]) );
	reset();
}
