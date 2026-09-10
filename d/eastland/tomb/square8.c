#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("地下廣場");
	set_long( 
@C_LONG_DESCRIPTION
哇......這□是一個巨大的廣場，在經過那麼長久的路程後，這兒令你有豁然開朗的感
覺。實在無法想像當年的工匠們是如何在地底下建立如此大的廣場，你不禁對那些工匠起了
分敬意。廣場上空空蕩蕩的，似乎沒有任何生物存在，也許早就死光了。你看到東邊似乎有
不尋常的東西。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east"  : TOMB"/square7",
		"west"  : TOMB"/square9"  ]) );
	reset();	
#include <replace_room.h>
}

