#include "oldcat.h"

inherit ROOM;

int be_searched;
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
     "northwest" : ONEW"wild10",
     "northeast" : ONEW"wild16" ]) );
set("item_desc",([
    "moss":"@@look_moss",
    ]) );
set("search_desc",([
    "here":"@@to_search_here",
    "moss":"@@to_search_moss"
    ]) );
set_outside("eastland");
reset();
}

string look_moss()
{
  if (!this_player()->query_temp("r/check"))
    return "你想看什麼 ?\n";
  return "一片暗紅色的苔蘚，苔蘚下似乎閃著亮光。\n";
}

string to_search_here()
{
  string str;
  str="當你搜索這地方的時候,你發現有片苔蘚(moss)底下閃閃發光。\n";
  this_player()->set_temp("r/check",1);
  return str;
}

int to_search_moss()
{
    object ob1;

    if (!this_player()->query_temp("r/check"))
       return 0;
    if (be_searched!=0)
    { write(
        "你沒有找到任何東西。\n");
      return 1;
    };
    tell_room(this_object(),
         "你翻開苔蘚，發現了一個紅色巧克力\n"
         );
    this_player()->delete_temp("r/check");
    be_searched=1;
    ob1=new(OOBJ"r_chocolate");
    ob1->move(this_object());
    return 1;
}

void reset()
{
  ::reset();
  be_searched=0;
}
