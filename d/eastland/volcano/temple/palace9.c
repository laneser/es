#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int be_get;
void create()
{
	::create();
	set_short("龍宮寶庫" );
	set_long(
@LONG
這裡是龍宮寶庫，天下的奇珍異寶可能都在這裡找的到，更不用講那些普通
的真珠、瑪瑙、紅,藍寶石等等．．．．．不過東西實在是太多了，連龍王這
樣博聞強記的人也記不了全部。
LONG
	);
	set( "exits", ([
	     "east" : OTEMP"palace4",
	    ]) );
        set("pre_exit_func", ([
             "east":"to_east"
             ]) );
        set("search_desc",([
            "here":"@@to_search_here"
            ]) );
        set("light",1);
        reset(); 
}

string to_search_here()
{
  string str;
  object ob;

  if (be_get)
    str="你在這寶庫中找半天，找不到真正對你有用的東西。\n";
  else {
    str="你在這寶庫中搜索，在一個檀木箱子中，找到一個闢水珠。\n";
    ob=new(OOBJ"waterball");
    ob->move(this_object());
    be_get=1; }
  return str;
}

int to_east()
{
  printf("\n你穿過一片紅光，離開寶庫。\n");
  return 0;
}

void reset()
{
  ::reset();
  be_get=0;
}
void init()
{
   if(this_player()) this_player()->set_explore("eastland#39");
}
