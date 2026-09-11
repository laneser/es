#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓深處");
	set_long( 
@C_LONG_DESCRIPTION
你來到了陵墓的最深處。一具巨大的玉棺放置於此，上面有著東方王國的國徽，它的外
型古拙，而且找不任何一絲的接縫，就像是從一大塊巨大的玉石中雕刻出來似的，你想這應
該就是皇帝的棺木吧。四周的牆壁都是用黃金打造而成，上面一共鑲了九條白金鑄成的飛龍
，氣派非凡。你可以看到在石棺前的供桌上有著龍袍、皇冠、以及一顆閃閃發光的紅寶石，
這就是在南邊可以看到紅光的原因。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner5" ]) );
	set( "objects", ([
		"robe" : ITEM"/robe",
		"crown" : ITEM"/crown",
		"ruby" : ITEM"/ruby" ]) );
	set( "pre_exit_func", ([
		 "south" : "check_eq" ]) );
	reset();	
}

void init()
{
  if( this_player()) this_player()->set_explore("eastland#36");
}
int check_eq()
{
	if ( !present( "emperor robe", this_object() ) || !present( "emperor crown", this_object() ) )
	{	tell_room( this_object(),
		"\n"+"突然一塊巨大無比的石頭 ---- 「隔世石」，掉下來擋住南邊的出口。\n" );
		delete( "exits/south" );
		return 1; }
	else return 0;
}
