#include "saulin_temple.h"

inherit ROOM;
int got;

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
	got=0;
    set_outside("eastland");
	set( "exits", ([
		 "north" : SAULIN"towers4",
      	 "east"  : SAULIN"towers4",
		 "west"  : SAULIN"towers3",
		 "south" : SAULIN"towers5",
	]) );
	reset();	
}

void init()
{
	add_action( "summon_seed", "call" );
        if (this_player()) this_player()->set_explore("eastland#32");
}

int summon_seed(string arg)
{
	if( !arg || arg=="" || arg !="relic")
	{
 		tell_object(this_player(), 
    		"一個虛無縹緲的聲音道: 你鬼叫鬼叫個什麼勁？\n" 
   		);
	return 1; }
	if ( got ) {
        tell_object(this_player(), 
        	"你叫了好半天，連個鬼影子也沒有。\n" 
        );
	return 1; }
        tell_object(this_player(),@GOT_SEED
你叫了幾聲，突然一顆閃亮的光點向你飛來，你伸手一接，果然是顆舍利子。
GOT_SEED
		);
		got=1;
   		new( SAULIN_OBJ"magic_seed" )->move( this_player() );
  	return 1;
}

void reset()
{
    ::reset();
	got=0;
}
