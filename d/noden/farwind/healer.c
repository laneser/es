//#pragma save_binary

// translation done 2-21-94 -Elon

#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("屋內");
	set_long( @C_LONG_DESCRIPTION
你現在進入了一間雖然小，但是十分明亮乾淨的小屋，一張木製的
長方桌子，幾隻木製的椅子，顯示這裡的主人生活頗為簡單，你可以看
到牆壁上掛著一些風乾的草藥、植物、以及一些不知名的東西。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"out" : "/d/noden/farwind/w_gate" ]) );
	set( "objects", ([ 
		"healer" : "/d/noden/farwind/monster/healer" ]) );
	reset();
#include <replace_room.h>
}

void init()
{
	if( this_player() ) this_player()->set_explore( "noden#4" );
}