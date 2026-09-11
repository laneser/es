#include "hole.h"

inherit ROOM;

void create()
{
	object akaba;
	::create();
	set_short( "王宮寢室" );
	set_long(@LONG
這間房間是蜥蜴人大將軍阿卡巴的住所。阿卡巴在這個國度裡可
以算是一等一的戰士，手上的雙斧不知道擊敗多少好漢。
LONG
		);
	set( "exits",([
			"southwest" : HOLE"hole36",
			]) );
	akaba = new( HMONSTER"imperator" );
	akaba->move( this_object() );
	reset();
}

int clean_up() { return 0; }
