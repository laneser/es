#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("南大街");
	set_long( @LONG
你走正走在「巫咸城」內南大街上，大街往東邊方向延伸，北邊則是西大街，
往東可通往南門口。在這條南大街上還有許多古色古香的建築物，因為年代久遠，
不少凋臺危樓，更兼有不少死角，而北銜西大街，龍蛇混雜，治安令人深憂。  
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"ss",
       	   "north" : SCITY"ws",
        ]) );
	reset();
}
