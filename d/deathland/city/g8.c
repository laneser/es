
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Hero","英雄墓場");
  set_long(@Long
這裡是矮人英雄的墓場,墓場裡埋藏著一位有著偉大探險精神的人.這一座墓碑的碑銘
上寫著: 開路的先鋒.
Long
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
            "east":Deathland"/city/g7",
            "north":Deathland"/city/g9",
             ]));
reset();

}

string search_here()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++)
      if ( (string)items[i]->query("name") == "Black Box of Molader" )
        {
          if ( items[i]->query("quest_item/explorer_bell") )
             return "你已經找到過這個鈴當了,留給別人來拿吧!\n";
          items[i]->set("quest_item/explorer_bell",1);
          return "你發現了一串奇怪的鈴當掛在墓碑上,似乎是這個探險家的遺物.\n" 
                 "於是你順手拿了一個鈴鐺.\n";
        }  
    return "你找了又找, 發現有一串鈴鐺掛在墓碑上, 你不知道究竟它有甚麼\n"
           "用, 所以就不去理會它了, 也許只是裝飾品吧.\n";   
}

