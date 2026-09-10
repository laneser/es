#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("南大街");
	set_long( @LONG
你正走在「巫咸城」內南大街上，大街往東、西方向延伸，從這裡往南走可到
達南門口。北邊砌了幾面新牆，那原本是通向城內最主要的大道，卻因為某些緣故
，特地把它封了起來。在南大街上還有許多古色古香的建築物，因為年代久遠，不
少凋臺危樓，城主命人大肆整建一番，平時用以吸引觀光人潮。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "east" : SCITY"se",
       	    "west" : SCITY"sw",
       	   "south" : SCITY"southgate",
        ]) );
	set("objects", ([
	   "visitor":SWMOB"visitor2"
	]) );
	reset();
}
