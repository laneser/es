// File: /d/noden/asterism/city_garden.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("席藍洛斯花園");
	set_long( 
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩(asterism)城的花園,由半身人族長席藍洛斯一世
開始建立的,直到現在這花園的規模已經相當龐大了,但是由於這裡的地
勢太高,所以這裡的花草都是屬於寒帶的植物.往北你將回到大道路,而往
南邊走是一棟巨大的建築物 ,隱隱約約的在南邊你看到一座很高的塔.東
邊是一棟造形特殊的房子.從這裡看過去你只能知道那是培養植物的溫室。
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
	set( "exits", ([ 
		"north":ASTR"city31",
		"south":ASTR"city_library",
		]) );
	reset();
#include "replace_room.h"
}
