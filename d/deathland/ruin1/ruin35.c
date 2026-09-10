
// Deathland/ruin1/ruin35.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟");
     set_long(@Long
Long
,@CLong
在這裡你發現這個地方是一個平常人所居住的房子 ,這裡與遺蹟其它的地方完
全不同 .明顯地有著人類居住在這裡 .由這裡的擺設你能瞭解到這個地方的主人一
定相當的有學問 ,因為這個地方幾乎快要被書給淹沒了 .
CLong
);
     set("item_func",([
          "books":"look_books",
          "book":"look_book",
          ]) );
     set("search_desc",([
          "floor":"@@search_floor"
          ]) );
     set("objects",([
         "ranger":Deathland"/monster/ranger",
         ]) );
     set("exits",([
         "south":Deathland"/ruin1/ruin34",
         ]) );
     ::reset();
}

int look_books()
{
    write(can_read_chinese()?
          "一座書山 ,\或許你能找出一些有用的知識 ,但是如何從這些書中發現\n"
          "你想要的呢 ?\n":
          "NEEd to work");
    return 1;    
}

int look_book()
{
    write(can_read_chinese()?
          "你想要看那一本書呢 ?\n":
          "Which book do you want to look ?\n"
         );
    return 1;      
}

string search_floor()
{
     object *items,who;
     int i;
     
     who=this_player();  
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if ( items[i]->query("quest_action/pepper_find") ) {
          items[i]->set("quest_item/summon_pepper",1);
          return "你搜尋地板時, 發現了一瓶胡椒粉.\n";
          } 
     return "地板似乎有點奇怪, 但你無法確定.\n";
}
