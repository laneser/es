#include "../../story.h"
inherit SHOP;
void create()
{
	::create() ;
	set("light", 1) ;
	set_short("商店");
	set_long(@C_LONG
歡迎來到「巫咸城」最大的一家商店，這家商店是往來遊客、商人們以及國民
最常光顧的地方。在商店□你除了可以買(buy)、賣(sell)、估價(value)、或只是
參觀(list)以外，老闆還願意「免費」為你鑑定你身上的東西，把你想要鑑定的物
品拿給老闆，他就會告訴你物品的正確名稱。
C_LONG
	);
	set( "exits", ([ "east" : SCITY"es.c" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );
        set("pre_exit_func",([
            "east":"can_pass"]));
	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
//	replace_program(SHOP);
}
void init()
{
   ::init();
   write("\n\n商店老闆說道：歡迎光臨，請問這位客倌要點什麼？\n\n");
}
int can_pass()
{
   write("\n\n商店老闆說道：謝謝惠顧，請下次再來。\n\n");
   return 0;
}