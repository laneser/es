#include "../oldcat.h"

inherit ROOM;

int be_get;
void create()
{
	::create();
    set_short("後院");
	set_long( 
@LONG_DESCRIPTION
這裡是神殿的後院，在靠近圍牆的地上種著一棵果樹，有條小路可通到後殿。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple14",
     "southwest":OTEMP"temple25"
     ]) );
set("pre_exit_func",([
    "east":"to_leave",
    "southwest":"to_leave",
    ]) );
set("search_desc",([
    "here":"一棵枝葉茂密的大樹(tree)立在這院子的一隅。\n",
    ]) );
set("item_desc", ([
    "tree":"@@look_tree",
    "fruit":"@@look_fruit",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_hit","hit");
  add_action("do_spread","spread");
}

string look_tree()
{
  if (be_get)
    return "一棵枝葉茂盛的果樹。\n";
  return "一棵枝葉茂盛的果樹，上面還有一個果子，你仔細看那果子，竟然是人形，\n難道．．．．這就是那千年結一次果的人參果(fruit)。\n";
}

string look_fruit()
{
  if (be_get)
    return "what do you want to do?\n";
  return "這個果子有頭、有腳、有身體、也有手，當風吹過時，彷佛手腳還會動來動去。\n";
}

int to_leave()
{
  this_player()->delete_temp("spread_cloth");
  return 0;
}

int do_spread(string arg)
{
  if (!arg || ((arg!="cloth")&&(arg!="布"))) return 0;

  if (!(present("square cloth",this_player())))
    return 1;
  
  printf("你把布攤開，鋪在地上。\n");
  this_player()->set_temp("spread_cloth",1);
  return 1; 
}

int do_hit(string arg)
{
  object ob;

  if (!arg || ((arg!="fruit")&&(arg!="果子"))) return 0;
  
  if (!(present("small club",this_player()))) {
    write("這棵樹搖突然說起話來：唉呦、請不要用奇怪的東西亂敲我的身體，好嗎?\n");
    return 1;
  }
  
  if (be_get)
    return notify_fail("what do you want to do?\n");
  
  if (!this_player()->query_temp("spread_cloth")) {
    write("你用小槌子往那人參果輕輕的敲去，只見人參果一落地就鑽到土裡了。\n");
    be_get=1;
    return 1;
  }
  
  write ("你用小槌子往人□果輕輕敲去，只見人參果掉了下來，剛好落在你鋪的布上，你把它連布一起拿起來。\n");
  ob=new(OOBJ"fruit");
  ob->set(this_player()->query("name"),1);
  ob->move(this_player());
  be_get=1;
  return 1;
}

void reset()
{
  ::reset();
  be_get=0;
}
