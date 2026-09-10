#include <mudlib.h>

inherit "/std/seller";
inherit "/std/room/room";
void create()
{

	object boss;
	::create();
	set_short("冒險工具專賣店");
	set_long( @C_LONG_DESCRIPTION
你來到了冒險者公會內附設的冒險工具專賣店，一些有經驗的冒險者
在經過漫長的旅行後發現，有一些工具，是能夠保證平安完成冒險的鎖鑰
，而另一些則對冒險有很大幫助。為了幫助後進，他們在工會中開設了這
個店，如果你馬上要出發去探險，先來逛逛這兒倒是不錯的主意。
牆上貼了一張價目表(menu)，上面寫著出售物品的種類和價格。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set( "exits", ([
	             "east" : "/d/adventurer/hall/adv_libra1",
	             "west" : "/d/adventurer/hall/adv_shop1",
	                                         ]) );
	   boss = new( "/obj/morish" );
	   boss->move( this_object() );
//	set( "objects", ([
//	             "boss" : "/u/t/takeda/morish"
//	                 ]) );
	set_inventory( ({
/*
		({ "/d/eastland/goomay/obj/travel_bag", 5, 5 }),
*/
		({ "/d/adventurer/hall/weapons/adv-blade", 5, 5 }),
		({ "/d/noden/moyada/obj/pick",2,2 }),
		({ "/d/adventurer/hall/obj/salt_bottle",20,20 }),
		({ "/d/adventurer/hall/obj/knife",5,5 }),
		({ "/d/noden/moyada/obj/shovel",2,2 }),
		({ "/d/deathland/object/broom",1,1 }),
		({ "/obj/bandages",10,10 }),
	}) );
	seller::reset();
}
void init()
{
        ::init();
        seller::init();
// add_action("dont_update", "update");
//      add_action("dont_renew", "renew");
        return ;
} 
int dont_update()
{
        if (!wizardp(this_player()) ) return 0;
        else write("sorry, please dont update here\n");
        return 1;
} 
int dont_renew()
{
        if (!wizardp(this_player()) ) return 0;
        else write("sorry, please dont renew here\n");
        return 1;
}               
reset()
{
	room::reset();
	seller::reset();
}
int clean_up() { return 0; }
