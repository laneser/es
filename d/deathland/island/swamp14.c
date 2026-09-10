
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("swamp of GreyIsland","灰暗之島的沼澤");
  set_long(@Long
Long
,@CLong
一個黑漆漆的沼澤, 沼澤下似乎有著可怕的生物想把你拖下去, 你必須小心謹慎
你的每一步. 這裡沼澤的水似乎很深, 而且你的視線也被霧幾乎完全地遮住了. 這裡
你已經無法清楚地看到四周的狀況了, 只知道你的腳已經快深陷於沼澤裡了. 仔細看
看腳底似乎有著一種奇怪的蘑菇(mushroom)生長著.
CLong
);


set("exits",([
     "south":Deathland"/island/swamp15",
     ]) );
set("item_func",([
    "mushroom":"look_mushroom",
    ]) );
set("exit_invisble",1);     

::reset();
}


void init()
{
    add_action("to_pluck","pluck");
}

int to_pluck(string str)
{
    object *items;
    int i;
    if (!str||str!="mushroom") return 0;
    
    items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ){
          write("你摘了一些蘑菇放入你的黑盒子裡.\n");
          items[i]->set("quest_item/grey_mushroom",1);
          return 1;
          }
     write("你看了看這些蘑菇,似乎沒有甚麼用途, 順手把它丟掉了.\n");
     return 1;     
}

int look_mushroom()
{
    this_player()->set_explore("deathland#24");
    write("一種奇怪的灰色蘑菇, 似乎可以摘(pluck)一些來看看\n");
    return 1;
}
