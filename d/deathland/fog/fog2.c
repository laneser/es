// Deathland/fog1.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("Fog","霧中");
    set_long(@Long
Long
,@Clong
一遍大霧把你的視線完全籠罩住了,你的方向感已經完全的失去了
Clong
	);
   set("search_desc",([
       "here":"@@to_search_here",
       "blowhole":"@@to_search_blowhole",
       ]) );
   
   set("c_item_desc",([
       "blowhole":"一些冒著霧氣的氣孔.\n",
       ]) );
   
   set("exits",([
       "east":Deathland"/fog/fog2",
       "west":Deathland"/fog/fog2",
      // "north":Deathland"/fog/fog2",
      // "south":Deathland"/fog/fog2",
      ]) );
   reset();    

}
void init()
{
    // add_action("","");

}

string to_search_here()
{
   
   return "你仔細的尋找出路的時候,你發現地上充滿著一些氣孔(blowhole)冒出霧氣\n"
          "原來那就是霧不會消散的原因.\n";

}

string to_search_blowhole()
{
  return "這些在地上的氣孔的形狀千奇百怪,而且排列的位置相當奇怪,似乎形成一種.\n"
         "特殊的符號.\n"; 
}
