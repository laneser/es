#include "hole.h"

inherit ROOM;
void create()
{
	::create();
	set_short( "地下洞穴" );
	set_long(@LONG
一個黑漆漆的地下洞穴，陣陣的冷風由四面八方吹來，令你不停
的顫抖；然而當你靜靜地聆聽時，好像還有潺潺的水聲夾在風聲之中
。黑暗之中，你隱約覺得似乎有雙貪婪的眼睛正在打量著你。你不得
不提高戒心，以免隨時有猛獸從洞穴跑出來。
LONG
		);
	set( "exits",([
			"south" : HOLE"hole14",
			"northeast" : HOLE"hole16",
			]) );
	reset();
#include <replace_room.h>	
}