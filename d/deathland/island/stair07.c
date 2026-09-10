
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("stair","通往地底的階梯");
  set_long(@Long
Long
,@CLong
你位於一個階梯上,這階梯以螺旋狀靠在巖壁上往下延伸著. 你已經快到底了.
CLong
);

set("exits",([
     "up":Deathland"/island/stair06",
     "down":Deathland"/dwarf/muse31",
     ]) );
set("pre_exit_func",([
    "down":"to_down",
    ])); 

 ::reset();
}

int to_down()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if (items[i]->query("quest_item/crystal_card")) {
          return 0;
          }
    return 1;   
}
