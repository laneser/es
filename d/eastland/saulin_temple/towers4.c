#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("塔林");
	set_long( @C_LONG_DESCRIPTION
一座座小塔將這個小丘裝點的像一座叢林，這裡就是少林寺著名的塔林，
相傳每一位高僧坐化以後所得的舍利子都會建一座小塔來存放，看到這麼多的
塔，你可以想見少林的歷史悠久與人才輩出為什麼能聞名於世。
C_LONG_DESCRIPTION
	);
        set_outside("eastland");
	set( "exits", ([
		 "north" : SAULIN"towers3",
      	 "east"  : SAULIN"towers4",
		 "west"  : SAULIN"towers2",
		 "south" : SAULIN"towers4",
	]) );
	reset();	
}

void init()
{
    add_action( "summon_seed", "call" );
}

int summon_seed(string arg)
{
	if( !arg || arg=="" || arg !="relic")
 		tell_object(this_player(), 
    		"一個虛無縹緲的聲音道: 你鬼叫鬼叫個什麼勁？\n" 
   		);
    else
        tell_object(this_player(), 
                "你叫了好半天，連個鬼影子也沒有。\n" 
        );
   	return 1;
}
