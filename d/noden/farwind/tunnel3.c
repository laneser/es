//#pragma save_binary
 
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
	::create();
    set_short("地穴");
	set_long( @C_LONG_DESCRIPTION
你來到一個比較寬敞的地穴，洞穴頂部不斷地有水滴滴下來，在地上滴出
一個小水池( pool )，你注意到水池旁邊有幾個小土堆，其中一個土堆旁邊嚇
然躺著一具白骨( skeleton )。
C_LONG_DESCRIPTION
	);
 
	set( "exits", ([
		"northeast" : "/d/noden/farwind/tunnel2.c",
	]) );
   set( "item_desc", ([
	"pool" : "一個相當淺的小水池, 裡面似乎有些東西。\n",
	"skeleton" : "一具相當殘破的枯骨, 它的手骨似乎正指向水池。\n",
	]) );

        set("search_desc",([
                     "pool" : "@@to_search_pool"
                  ]));

	set( "objects", ([
		"crazy rat" : "/d/noden/farwind/monster/crazy_rat"
	]) );
	reset();
}

void init()
{
	if( this_player() ) this_player()->set_explore( "noden#2" );
}

int to_search_pool()
{
   if( present("crazy rat",this_object()) )
   {
	write( "先把瘋老鼠趕走吧!\n" );
	return 1;
   }
  write("你靠近水邊，不小心一腳採下去！哎～～\n");
  this_player()->move_player("/d/noden/drow/r41","SNEAK");
  return 1;
}
