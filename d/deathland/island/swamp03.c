
#include "../echobomber.h"

inherit ROOM;

void bottle_find();
int bottle_num;

void create()
{
	::create();
  set_short("swamp of GreyIsland","灰暗之島的沼澤");
  set_long(@Long
Long
,@CLong
一個黑漆漆的沼澤, 沼澤下似乎有著可怕的生物想把你拖下去, 你必須小心謹慎
你的每一步. 越往東走沼澤的水就越深, 而且你的視線也被霧幾乎完全地遮住了. 這
地裡你已經無法清楚地看到四周的狀況了, 只知道你的腳已經快深陷於沼澤裡了.

CLong
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
     "northeast":Deathland"/island/swamp04",
     ]) );
set("exit_invisble",1);     
::reset();
}

void init()
{
     bottle_find();

}

void bottle_find()
{
     object *items;
     int i;
     
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/crystal_card"))
             write("你的水晶卡片在這裡忽然一陣震動, 似乎這裡有著一個神秘的物品.\n");

     return;
}

string search_here()
{
     object *items;
     int i;
     
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/crystal_card")){
             items[i]->set("quest_item/black_bottle",1); 
             return "在沼澤裡你發現了一個黑色的瓶子\n";
             } 
     return "似乎沼澤裡有些什麼? 但是那是有用的物品嗎? \n";        
}
