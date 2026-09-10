
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("mountain of GreyIsland","灰暗之島的山嶽");
  set_long(@Long
Long
,@CLong
你沿著小徑慢慢地來到了山頂上, 這地方實在是個很古怪的場所, 雖說是灰暗島
的山頂, 但是你卻看到你的頭頂上有著厚厚的紅泥土與岩石, 你也看到你的底下有著
流動快速的河水.
    東邊有著一道很強勁的力場阻擋著你繼續前進. 那道力場似乎有著一種神奇的力
量, 須要有著特殊的物品方能讓你通過.
CLong
);

set("exits",([
     "southwest":Deathland"/island/mountain01",
     "east":Deathland"/island/mountain03",
     ]) );
set("pre_exit_func",([
    "east":"to_east",
    ])); 
 ::reset();
}

int to_east()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if (items[i]->query("quest_item/crystal_card")) {
          write("你的水晶卡與力牆的力量相應,於是你通過了力牆.\n");
          return 0;
          }
    write("你無法通過力牆.\n");
    return 1;   
}
