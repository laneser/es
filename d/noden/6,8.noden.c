#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("道路");
	set_long( @LONG_DESCRIPTION
你現在正走在一條碎石鋪成的道路上，沿著道路往北你可以看到諾達尼亞
的市街，諾達尼亞城位於米格蘭山的山腳下，幾百年來一直是諾頓王國的首都
與第一大城，也許你該進去看一看。路邊豎著一塊新漆好的牌子，上面寫著「
天馬號飛船載客站」。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
		"west" : "d/noden/5,8.noden", 
		"north" : "/d/noden/nodania/nodania_r1", 
		"south" : "d/noden/6,9.noden", 
		"east" : "d/noden/7,8.noden" ]) );
	set( "no_monster", 1 );
	set( "original", "d/noden/6,8" );
	set( "virtual_server", "/d/noden/virtual/noden_server" );
	set( "x_coordinate", 6 );
	set( "y_coordinate", 8 );
	reset();
	replace_program(ROOM);
}

void init()
{
	if( !find_object("/d/std/cloud/airship_pegasus") )
		"/d/std/cloud/airship_pegasus"->frog();
}
