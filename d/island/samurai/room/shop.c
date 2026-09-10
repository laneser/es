//#pragma save_binary

#include "farwind.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Farwind Shop", "商店" );
	set_long(
			"Welcome to the biggest and the only shop in Farwind. This shop\n"
        "is always full of adventuerers from everywhere. Because of this,\n"
		"the shop owner is very familar with various strange stuff from\n"
        "most adventurers. You can buy, sell, value, and list in the shop. If\n"
		"you have something that you don't know its real name, the shop\n"
        "owner would be gald to tell you its name. Just give him the item,\n"
		"and he'll tell you what you wish to know.\n",
			"歡迎來到遠風鎮最大也是唯一的商店，這家商店是冒險者最常光顧\n"
		"的商店之一，因為遠風鎮素有冒險者故鄉之稱，這裡的老闆對冒險者從\n"
		"各地帶回來的各種稀奇古怪的東西都頗有研究，在商店裡你除了可以買\n"
		"(buy)、賣(sell)、估價(value)、或只是參觀(list)以外，老闆還願意\n"
		"「免費」為你鑑定你身上的東西，把你想要鑑定的物品拿給老闆，他就\n"
		"會告訴你物品的正確名稱。\n"
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
}

