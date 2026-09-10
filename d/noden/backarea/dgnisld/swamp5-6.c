#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "outside","dgnisld") ;
	set_short( "cellar",  "地洞" );
	set_long(
	    "A mired swamp, You feel watery here. You can see a broad area\n"
	"of swamp. There is a hole on the ground, and a mired atair to down.\n"
	"The feeling here is very bad.\n",
            "泥濘的沼澤，十分泥濘，你感覺到這是一片很大的溼地，小心別陷入泥\n"
        " 沼，那將會要你的命的。地上有一個往下的樓梯，不過它是用泥巴做的。\n"
        );
               
        set( "exits", ([  "down" : DGNISLD"swamp5-5",  ]) );
        set( "objects", ([ "mire hand 3" : DGNISLD"monster/mhand.c", ]) );
        reset();
}
