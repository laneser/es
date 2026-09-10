#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the mystic altar","神秘祭壇");
  set_long(@Long
Long
,@CLong
一處已廢棄多年的祭壇.但是仍然有祭祀的行動,某個人似乎利用這裡來進行一種秘密
的祭典.祭壇上有著一團熊熊烈火(fire)在燃燒著.
CLong
);
  set( "light",1 );
  set( "c_item_desc",([
       "fire":"一團烈火,似乎永遠不會熄滅的樣子,你想試著去熄滅(extinguish)那團火嗎? \n"
     ]) );
  
  set( "exits",([
             "south":Deathland"/dwarf/village_0a",
             ]));

  reset();
}

void init()
{
	add_action("to_extinguish","extinguish");
}

int to_extinguish(string str)
{
   object *items,who;
   int i,j;
   
   if (!str||str!="fire") return 0;
   who=this_player();
   items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if ( ( j=items[i]->query("quest_action/muse_filled") ) ) {
              if (j==3) { //紅色
              write("你把你黑色瓶子的水倒下去, 此時火暫時地小了些, 於是你趕快地\n"
                    "把火中的書拿出來. 就在你拿出書的同時, 火又再度地大了起來. \n"
                    );
              items->set("quest_item/study_book",1);
              who->set_explore("deathland#17");
              }
              else 
              write("你把你黑色瓶子的水倒下去,但是火卻一點也沒有變小.\n");
              items->set("quest_action/muse_filled",0);
              return 1;
              }
  write(
  "當你嘗試著去熄滅那一團火的時候, 你發現那團火中有一本厚厚的書籍, 但是由於火\n"
  "的溫度實在太高了, 你無法拿出那本書來. \或許你應開去找水來把火弄熄, 但是一般\n"
  "的水應開沒有辦法澆熄它的. 你能找到能夠弄熄這團熊熊烈火的水來嗎? \n");
   
   return 1;
}

