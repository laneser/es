// File: 5,5.island.c

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
別汙染環境喔！這小溪一路往西北流去。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,5.island", 
		"north" : ISLAND"5,4.island", 
		"east"  : ISLAND"6,5.island",
		"south" : ISLAND"5,6.island",
		]) );
	set( "original", ISLAND"5,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 5 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}
