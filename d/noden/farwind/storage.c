//#pragma save_binary

#include <mudlib.h>

inherit ROOM;

int cup;

void create()
{
	::create();
	set_short("儲物室");
	set_long( @C_LONG_DESCRIPTION
這裡是一間老舊的儲藏室，牆角、天花板到處佈滿蜘蛛網，地上一層厚
厚的灰塵。一些雜七雜八的東西到處散置，也許你可以發現一些有用的東西
。靠近牆邊有一個櫥櫃(cupboard)，裡面可能有一些有用的東西。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_desc", ([
		"cupboard" : "這個櫥櫃十分老舊，上面積滿了灰塵，也許你必須找\n"
					"一找(search)，才能確定裡面有沒有東西。\n"
	]) );

	set( "exits", ([
		"down" : "/d/adventurer/hall/adv_guild"
	]) );
	set( "objects", ([
		"knife" : "/d/noden/farwind/items/knife"
	]) );
	reset();
}

void init()
{
	add_action( "do_search", "search" );
}

void reset()
{
	::reset();
	cup = 1;
}

int do_search(string arg)
{
	object obj;

	if( !arg || arg!="cupboard" )
		return notify_fail( "你在倉庫中找來找去，弄得滿身灰塵。\n");
	if( cup ) {
		write( "你仔細搜索櫥櫃，結果只找到一個空紙杯。\n");
		obj = new("/d/noden/farwind/items/cup");
		obj->move(this_object());
		cup = 0;
		return 1;
	} else {
		write( "你把櫥櫃裡裡外外，上下左右都仔細看過一遍，只有灰塵和木屑。\n");
		return 1;
	}
}
