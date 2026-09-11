#include "hole.h"

inherit ROOM;

void create()
{
	object arthur;
	::create();
	set_short( "王宮寢室" );
	set_long(@LONG
這間房間是蜥蜴人騎士團團長『亞瑟』的住所。『亞瑟』目前是這個
國度裡騎士軍團的領導者。
LONG
		);
	set( "exits",([
			"east" : HOLE"hole42",
			]) );
	arthur = new( HMONSTER"colonel" );
	arthur->move( this_object() );
	reset();
}

int clean_up(){ return 0; }
