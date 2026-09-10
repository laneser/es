#include "dgnisld.h"

inherit ROOM;

void create()
{
	::create();
	set( "light", 0 ) ;
	set_short( "small hole", "小洞" ) ;
	set_long(
	    "Inside of the small hole, it's very dark and adust!\n"
	"The enterence is broken. There seems be a exit forward.\n",
	    "十分狹窄的洞，既乾燥又陰暗。入口已經毀了，前方不遠\n"
	"好像有出口。\n"
        ) ;
        
    	set( "objects", ([ "bats_king" : DGNISLD"monster/large_bat.c",
    	                   "small_bat" : DGNISLD"monster/bat.c",
    	                ])  );
    	reset();
	set( "exits", ([
	     "forward"    : DGNISLD"swamp5-5",	]) );
        set( "exit_msg", ([
             "forward"    : "$N climb up from the hole," 
                            "and the hole becomes broken.\n",   ])  );
}
