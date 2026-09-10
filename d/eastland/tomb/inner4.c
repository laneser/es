#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓角落");
	set_long( 
@C_LONG_DESCRIPTION
這兒是陵墓的角落，冷冷的銀光自星空灑下。你看到一些大箱子放在牆邊，然而它們似
乎都被鎖上了，令你頗覺懊惱。除此之外還有許多具兵馬俑擺在這兒，它們的神態栩栩如生
，一個個的眼光彷佛在注視著你，你想還是趕快離開這兒的好。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"south" : TOMB"/inner3",
		"west"  : TOMB"/inner5"  ]) );
	reset();	
}

void init()
{
	tell_object( this_player(), 
		"當你來到這兒時，那些兵馬俑的武器突然都往你身上招呼 !!\n"
		);
	this_player()->receive_damage(100);
}
