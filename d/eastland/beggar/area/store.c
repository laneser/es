//#pragma save_binary

#include "../dony.h"
inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short("商店");
	set_long(@C_LONG
歡迎來到『薪膽村』最大也是唯一的商店,這家商店是人們最常光顧的商店之
一。雖然這裡普遍貧窮,可是人們還是很樂意掏腰包買一些日常生活用品。在商店
□你除了可以買(buy)、賣(sell)、估價(value)、或只是參觀(list)以外,老闆還
願意「免費」為你鑑定你身上的東西,把你想要鑑定的物品拿給老闆, 他就會告訴
你物品的正確名稱。
C_LONG
	);
	set( "exits", ([ "out" : DBEGGAR"east3.c" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
	replace_program(SHOP);
}
