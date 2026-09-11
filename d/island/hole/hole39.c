#include "hole.h"

inherit ROOM;

void create()
{
	object abon;
	::create();
	set_short( "王宮寢室" );
	set_long(@LONG
這間房間是蜥蜴人劍術師『亞邦』的住所。『亞邦』在這個國度
裡負責教授年輕一代的蜥蜴人劍法。
LONG
		);
	set( "exits",([
			"northeast" : HOLE"hole36",
			]) );
	abon = new( HMONSTER"swordman" );
	abon->move( this_object() );
	reset();
}
