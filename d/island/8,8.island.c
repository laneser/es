// File: 8,8.island.c

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
別汙染環境喔！這小溪一路往東南流去。
LONG_DESCRIPTION
	);
	
        set( "underwater",1 );
	set_outside( "noden" );
	set( "exits", ([ 
		"east"  : ISLAND"9,8.island",
		"south" : ISLAND"8,9.island",
		]) );
	set( "original", ISLAND"8,8" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 8 );
	set( "y_coordinate", 8 );
        set( "objects" , ([
                  "fish #1" : IMON"s_fish.c",
                  "fish #2" : IMON"salmon.c"
                         ]) );     
        call_out( "flow_away",40 );
	reset();
	
}

void init()
{
     UNDERWATER -> apply_effect ( this_player(), 7, 1 );
}
void flow_away()
{
     int i;
     object *ob;
     
     ob = all_inventory( );
     i = sizeof( ob );
     
     while( --i>=0 )
     {  
        if( (int)ob[i] -> query ( "likefish" ) < 1 ) 
        {
        tell_object( ob[i],"\n\n 哇！ 你被水流走啦～～～～～～～ 唷呵！ \n\n" );
        ob[i] -> move_player( ISLAND"9,9.island.c" ,"SNEAK") ;
        }
     }
}     