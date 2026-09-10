#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("東大街");
	set_long( @LONG
你走正走在「巫咸城」內東大街上，大街往南、北邊方向延伸，可容納三匹馬
並行的寬度，而東邊是東門。東大街的地是用大理石鋪成的，整理的很乾淨。自從
主大道封閉已後，東大街變成了城中最熱鬧的地方，原因無他，因為許多重要的鋪
子都在這條東大街上。西邊是一家客棧。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"eastgate",
       	    "west" : SCITY"wine1",
       	   "south" : SCITY"es",
       	   "north" : SCITY"en1"
        ]) );
        set( "objects", ([
           "visitor":SWMOB"visitor2"
        ]) );
	reset();
}
