// File: /d/noden/asterism/tower2-6.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的頂層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中矮人高塔的頂樓，也就是矮人王阿萊特斯四世的臥室，
房間中央一個大床，但是上面的寢具卻和床不成比例。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"down" : ASTR"tower2-5",
		]) );
		
	set("objects",([
//          "king":MOB"dwarf_king",
	    "guard#1":MOB"dwarf_guard02",
	    "guard#2":MOB"dwarf_guard02",
	    ]) );
	reset();
}

void init()
{
   if( this_player() ) this_player()->set_explore("noden#35");
}
