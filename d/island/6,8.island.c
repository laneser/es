// File: 6,8.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("小溪");
	set_long( @LONG_DESCRIPTION
看來你還是受不了這清澈河水的召喚，悠遊在其中是十分愉悅的事，
不過要注意兩件事，第一、別忘了換氣，第二、雖然可以游水、抓魚，但
別汙染環境喔！這小溪一路往西南流去。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"5,8.island", 
		"south" : ISLAND"6,9.island",
		]) );
	set( "original", ISLAND"6,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 8 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}
     
