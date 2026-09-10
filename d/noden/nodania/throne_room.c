#include "nodania.h"

inherit ROOM;

void create()
{
	object king;

	::create();
	set( "light", 1 );
	set_short( "議事廳" );
	set_long(@CLONG
你來到了國王耶拉曼十一世的議事廳，國王平常都在這裡和大臣們
商討國事，議事廳的佈置和大廳差不多，國王的王座旁邊有兩張比較小
的座椅，分別是皇后和小公主的座位。南邊是王宮的大廳，東邊的迴廊
通往國王的圖書館，西邊則是皇后的收藏室。
CLONG
	);
	set( "exits", ([
		"south" : NODANIA"palace_hall",
		"west" : NODANIA"collection",
		"east" : NODANIA"e_throne"
	]) );
	set( "objects", ([
		"body guard#1" : NODANIA"monster/body_guard",
		"body guard#2" : NODANIA"monster/body_guard",
	]) );
	king = new(NODANIA"monster/yaramon_xi");
	king->move(this_object());

	reset();
}

int clean_up() { return 0; }
