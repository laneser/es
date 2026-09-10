#include "nodania.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set( "light", 1 );
	set_short( "迴廊" );
	set_long(@CLONG
這裡是王宮中的一處迴廊，在你的西邊是國王的議事廳，東邊是國王
的圖書室。一座雕飾精美的樓梯通往王宮二樓。
CLONG
	);
	set( "exits", ([
		"west" : NODANIA"throne_room",
		"east" : NODANIA"royal_lib",
		"up" : NODANIA"upstair_1"
	]) );
	create_door( "east", "west", ([
		"keyword" : ({ "oak door", "door" }),
		"name" : "oak door",
		"c_name" : "橡木門",
		"status" : "locked",
		"c_desc" : "一扇雕飾華麗的橡木門，。\n",
		"lock" : "KING_YARAMON_XI_LIBRARY"
	]) );
}
