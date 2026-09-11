
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
			"west" : HOLE"water17",
			"south" : HOLE"water15",
		]) );
	set( "exit_invisble",1 );
	set( "underwater",1 );
	reset();
	
}

void init()
{
	UNDERWATER->apply_effect( this_player(),4,3 );
	add_action( "to_out","out" );
}

int to_out()
{
	string him;
	
	him=this_player()->query( "c_name" );
	tell_room( environment(this_player()),set_color(
	him+"受不了水底環境，決定先出去喘口氣。\n","HIR"),this_player() );
	this_player()->move( HOLE"hole24","SNEAK" );
	this_player()->force_me( "look" );
	tell_room( environment(this_player()),set_color(
	him+"忽然從你面前的池塘中冒了出來。\n","HIY"),this_player() );
	return 1;
}