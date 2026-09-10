#include "nodania.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	seteuid(getuid());
	set( "light", 1 );
	set_short( "國王的圖書室" );
	set_long(@CLONG
你來到了國王耶拉曼十一世的專用圖書室，這裡的藏書雖然不及諾
達尼亞大圖書館豐富，但也是應有盡有。你可以從國王書櫃中的書籍種
類發現耶拉曼十一世對有關植物的書特別有興趣。
CLONG
	);
	set( "exits", ([
		"west" : NODANIA"e_throne"
	]) );
	create_door( "west", "east", ([
		"keyword" : ({ "oak door", "door" }),
		"name" : "oak door",
		"c_name" : "橡木門",
		"c_desc" : "一雕飾華麗的橡木門。\n",
		"status" : "locked",
		"lock" : "KING_YARAMON_XI_LIBRARY"
	]) );
/*
	set( "objects", ([
		"Annihilator": "/adm/gods/annihilator" ,
		"Kyoko": "/adm/gods/kyoko",
		"Layuter": "/adm/gods/layuter",
		"Echobomber": "adm/gods/echobomber", ]) );
*/
	reset();
}

void clean_up() { return 0; }
