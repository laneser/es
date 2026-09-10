//#pragma save_binary

// translation done -Elon 03-10-94
#include "moyada.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
   set_short( "主要道路" );
	set_long( @LONG_DESCRIPTION
你現在站在摩亞達城的主要道路，它大多以破碎的磚石所鋪制而成
。往南是城中心的圓形廣場與「銀色之塔」，向北則是北門。東邊有一
棟新蓋的木造房子。
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
	    "east"  : MOYADA"shop/wanfu_shop.c",
		"south" : MOYADA"mainrd5.c", 
		"north" : MOYADA"n_gate.c",  ]) );

    create_door( "east", "west", ([
        "keyword" : ({ "wooden door", "door", }),
        "name"    : "wooden door",
        "c_name"  : "木門",
        "c_desc"  : "全新的木門",
        "status"  : "open",
    ]) );
	reset();
}
