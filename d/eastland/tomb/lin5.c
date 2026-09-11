#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("竹林");
	set_long( 
@C_LONG_DESCRIPTION
你進入了一片竹林 !! 實在無法想像在地底下怎麼會有一片如此大的竹林，而且還長的
如此茂盛，真是令人吃驚。微風輕輕吹來，令你覺得十分舒服。你看到這些竹子的根部都被
一種奇異的光芒包圍著，大概這就是它們能在這兒存活下來的原因。在東邊有一幢精緻的小
屋，你想也許可以在那兒找到為何地底下會存在這樣一個地方的原因。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([
		"south" : TOMB"/lin4",
		"east" : TOMB"/house1",
		"west" : TOMB"/lin6" ]) ); 
	reset();	
#include <replace_room.h>
}

