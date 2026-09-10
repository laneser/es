#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("南大街");
	set_long( @LONG
你走正走在「巫咸城」內南大街上，大街往西邊方向延伸，北邊則是東大街。
東大街是城內最繁華的路段，人潮洶湧，絡驛不絕，許多重要的鋪子都在那裡。由
於南大街是出入城內外必經之地，這裡更是銜接著東大街，不時有巡邏捕役經過，
維持治安。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"ss",
       	   "north" : SCITY"es"
        ]) );
        set("objects", ([
           "policeman#1":SWMOB"wiz_guard2",         
           "policeman#2":SWMOB"wiz_guard2",
        ]) );
	reset();
}
