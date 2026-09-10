#include <hole.h>

inherit ROOM;

void create()
{
	object rasoda;
	::create();
	set_short( "王宮寢室" );
	set_long(@LONG
這間房間是蜥蜴人祭司『拉索達』的住所。『拉索達』目前是這個
國度負責魔法方面的一切事務。
LONG
		);
	set( "exits",([
			"west" : HOLE"hole42",
			]) );
	rasoda = new( HMONSTER"poutiff" );
	rasoda->move( this_object() );
	reset();
//#include <replace_room.h>
}
