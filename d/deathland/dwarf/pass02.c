
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("storage room","儲藏室");
  set_long(@Long
一間很大的儲藏室,裡面放著一堆雜七雜八的東西.有一個很長的梯子(ladder)通向上面
,而北邊有一間陰暗的地下室
Long
);

set("c_item_desc",([
    "ladder":"一道很長的梯子.\n",
   ]) );
set("exits",([
     "northdown":Deathland"/dwarf/pass01.c",
     ]) );
 ::reset();
}

void init()
{
 add_action("to_climb","climb");
}

int to_climb(string str)
{
  if(!str||str!="ladder") return 0;
  else {
    write("你爬上這梯子,花了許久的時間才爬完這個非常長的梯子\n");
    say(this_player()->query("c_name")+"爬上了梯子\n");
    this_player()->move_player(Deathland"/palace/pa_0b","SNEAK","");
    return 1;
  } 
}
