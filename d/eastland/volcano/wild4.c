#include "oldcat.h"

inherit ROOM;

int be_moved;
void create()
{
	::create();
	set_short("小樹林");
	set_long(
@LONG_DESCRIPTION
你站在一條小徑上，環繞著你的是一片小樹林，樹木的高度約只有比你的兩倍身高
再高一點，你在想經過了那麼漫長的歲月，為什麼這裡的樹還是這麼小呢，雖然只是小
樹林，但其中也是生氣勃勃，另外，你也發覺這附近的土石和別的地方比較，似乎也有
點也不一樣。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "northeast" : ONEW"wild9",
     "northwest" : ONEW"wild2", ]) );
set("item_desc",([
    "rock":"@@look_rock",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_push","push");
}

string look_rock()
{
  if (!this_player()->query_temp("g/check"))
    return "你想看什麼 ?\n";
  return "這塊灰色的石頭上有兩個凹下去的印子，彷佛是一對手掌。\n";
}

string to_search_here()
{
  string str;
  str="當你搜索這地方的時候,你發現有塊石頭(rock)底下閃閃發光，石頭表面似忽有\n個手掌印子。\n";
  this_player()->set_temp("g/check",1);
  return str;
}

int do_push(string arg)
{
    object ob1;

    if (!this_player()->query_temp("g/check"))
       return 0;
    if (!arg || arg!="rock")
    { write(
        "你想要效法愚公移山嗎？\n");
      return 1;
    };
    if (be_moved!=0)
    { write(
        "這塊石頭已經被移動過了。\n");
      return 1;
    };
    write("你移開石頭，發現了一個藍色巧克力\n");
    this_player()->delete_temp("g/check");
    be_moved=1;
    ob1=new(OOBJ"b_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_moved=0;
}
