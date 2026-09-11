#include "../hole.h"

inherit OBJECT;
void create()
{
	set_name( "A Saw","一把鋸子" );
	add( "id",({ "saw" }) );
	set_short( "鋸子" );
	set_long(@LONG
	一把鋒利的鋸子。
LONG
		);
	set( "weight",5 );
	set( "unit","把");
}           
