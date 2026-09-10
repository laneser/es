// File: 2,5.island.c

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
		"east"  : ISLAND"3,5.island",
		"south" : ISLAND"2,6.island",
		]) );
	set( "original", ISLAND"2,5" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 2 );
	set( "y_coordinate", 5 );
        call_out( "flow_away",5 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 3, 3 );
}
void flow_away()
{
     int i;
     object *ob;
     
     ob = all_inventory();
     i = sizeof( ob );
     
     while( --i>=0 )
     {  if( (int)ob[i] -> query( "likefish" ) < 1 )
        {
        tell_object(ob[i],"\n\n 哇！ 不妙，一股突如其來的海朝將你推到他處！ \n\n" );
        ob[i] -> move_player( ISLAND"1,6.island.c" ,"SNEAK" ) ;
        }   
     }
}     