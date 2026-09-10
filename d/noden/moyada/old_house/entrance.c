// translation done. -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("入口");
	set_long( @C_LONG_DESCRIPTION
你站在古老建築物(house)的大門前, 生鏽虛掩的鐵門被風吹得嘎嘎做響, 這裡寒
風刺骨, 風出奇的強, 藤蔓爬滿了牆壁, 越發覺得此處的可怕。門口站著兩隻石像鬼
, 似乎在警告你別進去。
C_LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([
		"south" : MOYADA"mainrd6",
	]) );
	set( "item_desc", ([
      "house" : "一棟古老而破舊的房子, 你膽子夠大的話, 也許能進去(enter)瞧瞧.\n"
	]) );
	set( "objects", ([
	  "gargoyle#1" : MOYADA"monster/gargoyle",
	  "gargoyle#2" : MOYADA"monster/gargoyle",
	]) );
	reset();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
   if( this_player() ) this_player()->set_explore("noden#8");
	write( "一陣莫明的恐懼讓你放棄這念頭!\n" );
	return 1;
}
