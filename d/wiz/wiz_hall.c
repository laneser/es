#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "巫師大廳" );
	set_long(
		"你現在正站在巫師領域的大廳之中，這個大廳是用某種白中帶著淡藍色紋\n"
	"路的石材建成的，一些綠色的植物和不知名的花卉裝飾著大廳四周的圓柱。北\n"
	"邊是著名的「巫師學院」，西邊是傳說中的「世界廣場」，往南則是巫師們辦\n"
	"公的所在地。東邊的牆上有一面巨大的鏡子。\n"
	);
	set( "light", 1 );
	set( "pre_exit_func", ([
		"east" : "to_farwind"
	]) );
	set( "exits", ([
		"east"  : "/d/adventurer/hall/adv_guild",
		"south" : "/d/wiz/wiz_office",
        ]) );
}

int to_farwind()
{
		write("你穿過鏡子，進入冒險者公會。\n");
	return 0;
}
