
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The Royal Dwarf graveyard","矮人皇陵");
  set_long(@Long
這裡是矮人皇室的墓場,墓場裡埋藏著歷代國王以及他的家人.
Long
);
set("exits",([
            "south" :Deathland"/city/g7",           
             ]));

set("echo_special_summon",1);
set("falady",1);
reset();
}


void init()
{
     this_player()->set_explore("deathland#13"); 
}


void summon(object player,object box)
{
     if ( !query("falady") )
       tell_object(player,
       "似乎沒有甚麼靈魂現在能被你招喚的.\n"
       );       
     else {
       tell_room(this_object(),
       "一個模糊的氣體逐漸成形....\n");
       set("falady",0);
       call_out("falady_appear_1",3,player,box);
       }
     
     return;
}

void falady_appear_1(object player,object box)
{
     object monster;
     tell_room(this_object(),
     "法拉第的靈魂出現了...\n");
     monster=new(Monster"/falady");
     monster->move(this_object());
     call_out("falady_appear_2",2,player,box,monster);
     return ;
}

void falady_appear_2(object player,object box,object monster)
{
   if ( environment(player) != this_object() )  {
     tell_room(this_object(),
     "法拉第看了看四周,然後消失了.\n"
     );
     monster->remove();
     set("falady",1);
     } 
   else if ( ! box->query("quest_item/queen_amulet") ){
     tell_object(player,
     "法拉第看了看你,說:為什麼要打擾我呢?\n");
     tell_room(this_object(),
     "法拉第看了看,然後消失了.\n"
     );
     monster->remove();
     set("falady",1);
     }
   else {
     tell_object(player,
     "法拉第看了看你說:我的母親要你來看我的??\n"
     "我也很想去看我的母親,但是我無法親自離開這裡, 你必須把我帶到我母親那裡去.\n"
     );
     set("falady",0);
     }
   return;
}

void reset()
{
   object monster;
   
   ::reset();
   if ( (monster=present("falady")) && monster->query("npc") ) 
      monster->remove();
   set("falady",1);    

}
