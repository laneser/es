#include "oldcat.h"

inherit ROOM;

int be_moved;
void create()
{
	::create();
	set_short("空地");
	set_long( 
@LONG_DESCRIPTION
這片空地只有長了一些雜草，大部份是一些大小不一的石頭，你發現這裡的石頭似
乎和別地方好像有點差別，顏色只有紅色的、黑色的，像是被火燒過的樣子，地面的土
壤和你所知的火山灰所形成的土相類似，你感覺這裡有點熱。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest" : ONEW"wild8",
     "south" : ONEW"wild10",
     "northeast" : ONEW"wild14" ]) );
set("item_desc", ([
    "cave":"@@look_cave",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_dig","dig");
}

string look_cave()
{
  if (!this_player()->query_temp("s/check"))
    return "你想看什麼 ?\n";
  return "一個小小的地洞，裡面黑黑的，看不到任何東西。\n";
}

string to_search_here()
{
  string str;
  str="當你在這地方翻天覆地時,一隻老鼠突然從你前面跑過，你仔細的觀察老鼠的\n"+
      "來處，發現一個老鼠洞(cave)，也許可以挖大一點看看裡面藏啥東西\n";
  this_player()->set_temp("s/check",1);
  return str;
}

int do_dig(string arg)
{
    object ob1;

    if (!this_player()->query_temp("s/check"))
       return 0;
    if (!arg || arg!="cave")
    { 
      write("你要挖石油嗎？\n");
      return 1;
    };
    if (be_moved!=0)
    { 
        write("這個洞穴已經被挖過了。\n");
      return 1;
    };
    tell_object(this_player(),
         "你挖開洞旁的土石，伸手進去摸索，發現了一個銀色巧克力\n"
          );
    be_moved=1;
    this_player()->delete_temp("s/check");
    ob1=new(OOBJ"s_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_moved=0;
}
