
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","河邊");
  set_long(@Long
Long
,@CLong
南面是一條流速極快的河川, 即使你站在河邊你一樣能感受到它的速度.
CLong
);

set("c_item_desc",([
    "river":"一條流速極快的河川.\n",
           ]) );

set("exits",([
     "east":Deathland"/dwarf/river03",
     "west":Deathland"/dwarf/river01",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    write("這河水流動的太快速了,假如你真的下河去的話,\或許你可以直接遊\n"
          "到閻羅王的面前.\n");
    return 1;      
} 
