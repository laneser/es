// File: 7,12.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;

void create()
{
	::create();
	set_short("岩石平臺");
	set_long( @LONG_DESCRIPTION
這岩石平臺在沼澤中十分顯明，平臺上十分平整，顯然是蜥蜴人用心
修整的結果，平常這臺上是沒有多少人的，只有進出的人經過，但是一發
生戰爭，蜥蜴人便在此集合兵馬，那是很壯觀的場面；這平臺中央便是洞
穴入口了，裡頭黑黝黝的，有點嚇人，拿出勇氣，下去看看吧！不過洞口
上有一個告示牌(sign)，也許你該看一看。
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"north" : ISLAND"7,11.island", 
		"down"  : "/d/island/hole/hole00"
		]) );
	set( "original", ISLAND"7,12" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 7 );
	set( "y_coordinate", 12 );
        set( "no_monster" , 1 );
        set( "item_desc",([ "sign":"由於失去神力的庇佑，洞內有很大的改變喔！\n" ]));
	reset();
#include <replace_room.h>
}

