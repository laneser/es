//#pragma save_binary

#include "farwind.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short("商店");
	set_long(@C_LONG
歡迎來到遠風鎮最大也是唯一的商店，這家商店是冒險者最常光顧
的商店之一，因為遠風鎮素有冒險者故鄉之稱，這裡的老闆對冒險者從
各地帶回來的各種稀奇古怪的東西都頗有研究，在商店裡除了可以買
(buy)、賣(sell)、估價(value)、或只是參觀(list)以外，老闆還願意
「免費」為你鑑定你身上的東西，把你想要鑑定的物品拿給老闆，他就
會告訴你物品的正確名稱。
C_LONG
	);
	
	set( "exits", ([ "west" : FARWIND"smain" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan",
		"shop owner" : FARWIND"monster/shopowner",
		"traveller" : FARWIND"monster/traveller"
	]) );
	reset();
	replace_program(SHOP);
}
