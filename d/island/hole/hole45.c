#include "hole.h"

inherit ROOM;

void create()
{
	object bulansido;
	::create();
	set_short( "領袖寢室" );
	set_long(@LONG
這間房間是素有『戰神』稱號的蜥蜴人領袖『古茲曼』的住所。
LONG
		);
	set( "exits",([
			"up" : HOLE"hole44",
			]) );
	bulansido = new( HMONSTER"leader" );
	bulansido->move( this_object() );
	reset();
//#include <replace_room.h>
}

int clean_up(){ return 0; }
