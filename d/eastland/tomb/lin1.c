#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("竹林");
	set_long( 
@C_LONG_DESCRIPTION
你進入了一片竹林 !! 實在無法想像在地底下怎麼會有一片如此大的竹林，而且還長的
如此茂盛，真是令人吃驚。微風輕輕吹來，令你覺得十分舒服，有點兒昏昏欲睡。你看到這
些竹子的根部都被一種奇異的光芒包圍著，大概這就是它們能在這兒存活下來的原因。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([
		"north" : TOMB"/lin6",
		"south" : TOMB"/lin2",
		"east" : TOMB"/lin4",
		"west" : TOMB"/square5" ]) ); 
	reset();	
#include <replace_room.h>
}

