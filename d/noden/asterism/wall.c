// File: /d/noden/asterism/wall.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("山壁");
	set_long(
		@C_LONG_DESCRIPTION
你走出了這片樹林。蟬鳴鳥聲依然縈繞在你的耳邊，久久不散。而矗立在
你面前的是一片光滑且近呼垂直的山壁。
C_LONG_DESCRIPTION
	);

        set("c_item_desc" , ([
                 "wall" : "這片山壁非常平滑,但是唯一奇怪的地方是."
                          "它上面有四個用途不明的洞。\n"
                          ]) ) ;
	set_outside( "asterism" );
//	set( "light", 1 );
	set( "exits",([ 
		"north" : ASTR"path4",
		]) );
        
	reset();
}
