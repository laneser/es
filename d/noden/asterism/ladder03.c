// File: /d/noden/asterism/ladder02.c

#include "asterism.h"


inherit ROOM;

void create()
{
	::create();
	set_short("通往山頂的石梯");
	set_long( 
		@C_LONG_DESCRIPTION
一座巨大的山峰聳立在你的面前,在貝爾基山脈的主峰,阿萊特山的
面前,你感覺到你是如此的渺小.你已經很接近艾斯特律恩城了,有個巨大
的告示板(board)被立在這裡。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
        "board":"----------------------------------------------------------------\n"
                "      矮人王阿萊特斯,地精長老埃乙爾,半身人族長席藍洛斯          \n"
                " 三人共同立碑與此,後代的子孫必須謹守下列的誓言..................\n"
                " 矮人族,地精族,與半身人將永遠和平共處於艾斯特律恩城中,共同抵抗外\n"
                " 來的侵掠,不得相互交戰於城內.                                   \n"
                "                      ---於最後一次地精--魔族對抗戰爭後一年.    \n"
                "----------------------------------------------------------------\n"    
          ]) );        

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"city_entrance", 
		"down" : ASTR"ladder02", 
		]) );
	reset();
#include "replace_room.h"
}
