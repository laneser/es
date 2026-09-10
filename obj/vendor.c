#include <mudlib.h>


inherit MONSTER;
inherit "/std/seller";
void create()
{
	::create();
	set_level(6);
	set_name( "vendor", "小販" );
	set_short( "小販" );
	set_long(
		"一個看起來很友善的小販，如果你有需要的話，可以向他購買物品，只要\n"
		"問他價錢(price)，他就會讓你看他的貨物。\n"
	);
	set( "race", "halfling" );
	set( "gender", "male" );
	set( "no_attack", 1 );
	set_inventory( ({
		({ "/obj/torch", 10, 10 }),
		({ "/obj/bandage", 10, 10 }),
		({ "/d/noden/farwind/items/pocket_map", 10, 10 })
	}) );
	set( "inquiry", ([
		"price" : "@@show_menu"
	]) );
}
void init()
{
	npc::init();
	seller::init();
}