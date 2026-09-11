
#include "hole.h"
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "水底" );
	set_long(@LONG
這是一處地下水彙集的的地層，蜥蜴人日常的飲用水
就是由此處供應的。不過這裡的水相當混濁，你甚至懷疑
這種水真的可以喝嗎？
LONG
		);
	set( "exits",([ 
			"south" : HOLE"water07",
			"north" : HOLE"water09",
		]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
}
