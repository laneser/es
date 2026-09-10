// File: /d/noden/asterism/dungeon/sewer12.c

#include "../asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("halfling tower", "下水道的入口");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		,@C_LONG_DESCRIPTION
這兒是艾斯特律恩城最引以為傲的下水道系統。 石牆上昏暗搖曳的燈光 , 
為這個長長的甬道憑添了些許詭異的氣氛。堅實的花崗岩牆, 寬達數尺的水道, 
再加上每隔十來步就有一片黑曜岩石板(slate)鑲在甬道壁上,  讓你覺得這個
設施的功能絕對不只是排水而已。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
	        "north": DUNGEON"sewer11",
                "east" : DUNGEON"sewer22",
                "south": DUNGEON"sewer13",  
		]) );
	reset();
}

void init()
{
     add_action("look_slate","look") ;
}

int look_slate(string arg)
{
    string msg ;
    string compared = ({ "slate" , "石板" , "黑曜岩石板"}) ;
    if( member_array(arg,compared,1) < 0 ) return 0 ;
    
    msg = CENTER->slate_desc(this_player(),this_object()) ;
    
    tell_object(this_player(),msg) ;
    
    return 1 ;
}


