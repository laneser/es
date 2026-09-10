//#pragma save_binary

#include <mercury.h>
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Small Shop", "小商店" );
	set_long(@AAA
這是一間小小不起眼的自助商店，僅僅提供著貨物買賣的功能，如果
你想問一下物品的價格，那只能看你的經驗來決定了，這裡不提供額外的
服務．
AAA
	);
	
	set( "exits", ([ "west" : MR"mar08" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );

	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
}

