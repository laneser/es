#include "../hole.h"

inherit OBJECT;

int filled;

void create()
{
	set_name( "Empty Bottle","空瓶子" );
	add( "id",({ "bottle" }) );
	set_short( "空瓶子" );
	set_long( "@@query_long" );
	set( "weight",5 );
	set( "unit","個");
	filled=0;
}           

string long()
{
	if( filled )
		return "瓶子裡面裝著些清水。\n";
	
	else 
		return "一個空瓶子，應該可以拿來裝水。\n";
}

int query_filled(){ return filled; }

void init(){ add_action( "fill_water","fill" ); }

int fill_water(string arg)
{
	object env;
	
	if( !arg || arg!="bottle" )
		return notify_fail( "用什麼裝水？\n" );
	if( filled )
		return notify_fail( "瓶子已經裝滿水了。\n" );
	env=environment(this_object());
	if( living(env) ) env=environment(env);
	
	if( !env->query( "water_source" ) )
		return notify_fail( "這兒的水不合適。\n" );
	
	filled=1;
	write( "你很快地將瓶子裝滿水。\n" );
	return 1;
}
	
