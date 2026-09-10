#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "巫師辦公室" );
	set_long( @LONG
這裡雖然是巫師們辦公的地方，但是巫師們平常大部份都呆在
自己的工作室。這裡主要是用來放一些巫師的留言板、工具( 玩具
 )等，稱作『巫師交誼廳』倒比較恰當。
    往北走你可以回到巫師大廳，在你的西邊是企劃室，東邊是品
管部，往南，則是大巫師的辦公室。
LONG
	);
	set( "light", 1 );
	set( "exits", ([
		"north"	:	"/d/wiz/wiz_hall",
		"south"	:	"/d/wiz/arch_office",
		"west"	:	"/d/wiz/planning",
		"east"	:	"/d/wiz/qc-request"
	]) );

	// Cause the wizard board to load
	call_other( "/d/wiz/wiz_board", "???" );
}
