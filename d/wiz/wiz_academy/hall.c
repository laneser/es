#include <mudlib.h>
#include "academy.h"

inherit ROOM;

void create()
{
	::create();
	set( "light", 1);
	set( "max_laod", 100000 );	
	set_short( "The Hall", "入口大廳" );
	set_long( @LONG
It needs work here.	
LONG
, @C_LONG
這裡是巫師學院的大廳, 由此可以前往學院中的幾個不同的部門。這
裡有三個主要的部門, 開始學習的新巫師們可以先前往西邊的控制部門,
在那裡你可以學到正式的巫師們所擁有的各種力量, 與如何使用這些力量
。進階的學生們則必須前往東邊的語言部門, 學習創造這個世界的語言--
LPC 的文法與規則。最後在北邊的實驗部門學習如何開始創造物品、生物
、與建造房間等, 並學習如何解決未知的問題。

    在你學完所有的課程之後, 北邊的實驗部門將會給你一道最後的考驗
。通過這道考驗, 你就能取得成為正式巫師的必要資格。
C_LONG
	);
	set( "light", 1 );
	set( "exits", ([
		"south"  : HERE"entry",
		"west"	: HERE"command_hall",
		"east"	: HERE"lpc_hall",
		"north" : HERE"work_hall"
	]) );
}
