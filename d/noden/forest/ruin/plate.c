#include "ruin.h"

inherit ROOM;

void create()
{
	::create();
	set_outside("noden");
	set_short("巨巖上的平臺");
	set_long(@CLong
眼前的景色讓你大吃一驚, 你站在一塊約數十公尺大的巨巖上, 下面是
一個廣大的盆地。從這裡俯瞰整個盆地, 底下一片翠綠。那下面全是樹, 除
了樹以外還是樹, 有如一個廣大的樹海一般。在樹海下面, 到底有什麼東西
隱藏著呢? 也許除了親自下到盆地中探探以外, 也沒有什麼別的辦法了吧!
但是, 路呢? 想攀爬數十公尺高, 光禿禿的巨巖簡直是拿自己的生命來開玩
笑!
    你的身後是原來的小徑, 附近似乎是沒有其他的出路了。
CLong
);
	set("exits",([ "back": FOREST"3n1w",]));
	reset();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg) 
{
	if( !arg || !(arg == "here" || arg == "plate") ) return 0;
	write( "巨巖邊竟然有條往下的路! 若不是仔細看還看不出來呢!\n" );
   if( this_player() ) this_player()->set_explore("noden#16");
//	set("pre_exit_func", ([ "down":"go_down", ]) );
	add("exits",([ "down" : RUIN"hidden_path" ]) );
	add("exit_suppress", ({ "down", }) );
	return 1;
}

void reset()
{
	::reset();
	set("exits",([ "back": FOREST"3n1w",]));
}
