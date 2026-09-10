#include <mudlib.h>
#include "/d/thief/thief.h"
inherit SELLER;
inherit ROOM;
void create()
{

	::create();
	set_short("贓物銷售中心");
	set_long( @C_LONG_DESCRIPTION
你現在來到了小偷公會內部所附設的銷贓中心，幫助小偷處理贓物, 並且提供
公會成員一些方便的道具。你可以看看牆上的價目表(menu), 看看這邊賣些什
麼東西。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/thief/hall/thief_guild" ,
		"west" : "/d/thief/hall/thief_storage" ,
	]) );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set_inventory( ({
		({ THIEF"hall/weapons/black_dagger", 5, 5 }),
		({ THIEF"hall/armors/cloth", 8, 8 }),
		({ THIEF"hall/misc/bag",3,3 }),
		({ THIEF"hall/misc/knife",3,3 }),
		({ THIEF"hall/misc/pushpin",30,30}),
		({ THIEF"hall/misc/bottle",10,10 }),
		({ THIEF"hall/misc/tape",40,40}),
	}) );
	seller::reset();
}
reset()
{
	room::reset();
	seller::reset();
}

