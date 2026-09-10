
#include <mudlib.h>

inherit ROOM;

int bushes = 1;

void create()
{
	::create();
   set_short("山丘");
	set_long( @LONG_DESCRIPTION
你正走在一由一些低矮山丘組成的丘陵地上，這裡的地勢起伏並
不很大，青黃交錯的短草皮覆蓋著舉目所及的山丘，幾株大樹(tree)
散佈在山坡上。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
          "east" : "/d/eastland/15,12.east" ]) );
   set( "original", "/d/eastland/14,12" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
   set( "x_coordinate", 14 );
   set( "y_coordinate", 12 );
   set( "c_item_desc", ([
        "tree" : "幾株疏疏落落的大樹。\n",
        "root" : "@@root_stat" ]) );
   set( "search_desc", ([
        "tree" : "你仔細地搜找這些樹木, 發現其中有株白楊木的樹根(root)有點奇特。\n",
        "root" : "@@search_root" ]) );
	reset();
}

void init()
{
   add_action( "push_bushes", "push" );
}

int push_bushes(string arg)
{
   if( !arg || arg != "bushes" )
   return notify_fail( "你把手往前虛推了幾下。\n" );
   write( "你把草叢撥開。\n" );
   bushes = 0;
   return 1;
}

string search_root()
{
   if( !bushes ) {
   this_object()->set("exits/hole","/d/eastland/ianyeu/hole");
     return "當你仔細地搜尋草叢之後的樹根時, 竟發現一個巢穴(hole)!\n";
   }
   return "你仔細地搜找樹根, 但是草叢(bushes)太多了。\n"
          "或許你應該先把它們推開(push)。\n";
}

string root_stat()
{
   if( !bushes )
   return "普通的樹根, 但是你看到被撥開的草叢後似乎有點古怪。\n";
   else return "普通的樹根。\n";
}

void reset()
{
   delete("exits/hole");
   ::reset();
}
