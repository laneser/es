//#pragma save_binary

#include "takeda.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "商店" );
	set_long(
		"這是梁山泊最大，也是唯一的一家商店，是惡名昭彰的時遷出資的\n"
		"，因為他開設的主要目的是銷售自己偷竊所得，為了吸引顧客，這裡的\n"
		"商品價格反而特別公道，也正因為如此，梁山泊的強盜們樂於將出外搶\n"
		"劫的所得在此寄賣，東方大陸跑單幫的客人也常來這裡蒐購便宜的商品\n"
		"。\n"
	);
	
	set( "exits", ([ "west" : TROOM"path2" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan",
		"owner" : "/d/noden/farwind/monster/shopowner",
		"shi" : TMONSTER"shi",
	]) );
	reset();
}

int clean_up() { return 0; }