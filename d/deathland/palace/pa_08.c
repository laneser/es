
#include "../echobomber.h"
#define QUEEN_SMILE Deathland+"/adm/queen_smile"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
set("light",1);
set_short("皇后莉莉絲的起居室");
  set_long(@Long
Long
,@CLong
這裡是皇后莉莉絲的寢宮.有一張床,一座化妝臺被放置在角落裡.除此以外,
並沒有任何多餘的物品.
CLong
);
set("echo_special_place",1);
set("exits",([
             "west":Deathland"/palace/pa_05",
             ]));
create_door("west","east",([
             "name":"gold door",
             "c_name":"金色的門",
             "keyword":({"gold door","door",}),
             "c_desc":"金色的門",
             "status":"locked",
             "desc":"a gold door",
             "lock":"ECHO_DWARF_CITY_1",
                     ]) );

set("objects",([
    "queen":Monster"/queen",
     ]) );
reset();
}

void init()
{
	this_player()->set_explore( "deathland#12" );
}

void release(object player,object box)
{
     int i;
     object *monster,falady;
     
     if ( (string)box->query("bottle_lock")=="leit" ) {
       tell_object(player,
      "萊特的靈魂被釋放後, 一下子就消失的無影無蹤了.\n");    
       box->delete("quest_action/bottle_lock");
       return; 
       }
     monster=all_inventory(this_object());
     for(i=0;i<sizeof(monster);i++) 
        if ( monster[i]->id("queen") && monster[i]->query("npc") ) {
          tell_object(player,
          "你釋放出法拉第的靈魂.\n"
          "法拉第慢慢地出現在你的面前.\n"
          );
          box->delete("quest_action/bottle_lock");
          falady=new(Monster"/falady");
          falady->move(this_object());
          tell_room(this_object(),
          "當皇后見到他兒子的時候, 高興地流下了眼淚.\n"
          "法拉第也是很高興,兩人於是聊了很久.\n",
          ({falady,monster[i],}) ); 
          call_out("quest_info",10,player,falady,box);
          return;
          } 
     box->delete("quest_action/bottle_lock");
     tell_object(player,
      "法拉第的靈魂被釋放後, 一下子就消失的無影無蹤了.\n");
     return; 
}

void quest_info(object player,object falady,object box)
{
     tell_room(this_object(),
     "過了很久, 法拉第向她母親揮揮手, 然後就消失了.\n"
     );
     falady->remove();
     tell_object(player,
     "皇后這時對你說: 謝謝你, 我已經知道我兒子在另一個世界裡活的很好.\n"
     "我也應該忘掉悲傷, 不要讓其他人為我擔心了.\n"
     "皇后愉快地微笑著.\n" 
     "**********************************\n"
     "你完成了這個艱難的任務.\n"
     "**********************************\n"
     );
     tell_room(this_object(),"皇后愉快地微笑著.\n",player);
     if ( (int)player->query_quest_level("queen_smile")< 5 )
       player->finish_quest("queen_smile",5);
     return;
}
