#include <../takeda.h>

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "vendor", "梁山黑商人" );
	set_short( "梁山黑商人" );
	set_long(@C_LONG
你看到一個全身黑衣的勁裝男子，背上背著一個大布包，從他的外貌與打扮你
認為他是一個商人，但是也許只有過去問他有關 price 的事才能證明你的想法
C_LONG
	);
	set( "race", "drow" );
	set( "gender", "male" );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "kar", 9 );
	set_skill( "dodge", 70 );
	set("player_invisible",1);
	set("max_fp",250);
	set("force_points",250);
	set_natural_weapon( 30, 20, 30 );
	set( "wealth/silver", 200 );
	set( "shop_name", "vendor" );
	set_inventory( ({
//		({ "/d/eastland/liang_shan/obj/flag", 2, 2 }),
		({ "/obj/bandages", 8, 8 }),
	        ({ "/d/thief/hall/misc/bag", 1, 1}),
	        
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