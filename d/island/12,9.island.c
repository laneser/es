// File: 12,9.island.c

#include <mudlib.h>
#include <conditions.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("淺海");
	set_long( @LONG_DESCRIPTION
這兒是靠近岸邊的的淺海，雖然深淺不一，但總在10公尺以內，海是
很危險的，隨時要注意自己的身體狀況，不要硬撐；唷！對了，這兒常有
暗潮，不小心可能會被衝得很遠。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"11,9.island",
		"north" : ISLAND"12,8.island",
		]) );
	set( "original", ISLAND"12,9" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 12 );
	set( "y_coordinate", 9 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}
