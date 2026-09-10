// File: /d/noden/asterism/tower2-5.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的第五層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中矮人高塔的第五層,矮人的會議室,許許多多的重大決定
都是在此地產生的。這裡有一個大的會議桌, 及數十張的椅子,牆上掛著一張矮人王
阿萊特斯一世的畫像(painting).除此之外,從窗口望出去,你能看到雄偉的高山聳立
著,上面還有一曾白霧籠罩著。
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
                "up"  :ASTR"tower2-6",
		"down":ASTR"tower2-4",
		]) );
	set("objects",([
	    "knight":MOB"dwarf_knight",
	    "mage"  :MOB"dwarf_mage",
	    ]) );
	reset();
}
