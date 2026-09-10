// Deathland/holyplace/f03.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    
    set_short("dark cave","黑暗的洞穴");
    set_long(@Long
Long
,@CLong
一片漆黑的地方, 除了黑暗還是黑暗, 一個奇異的駭骨橫置於洞穴的角落, 你覺
得有個力量似乎控制的地方. 
CLong
);
set("search_desc",([
    "skeleton":"@@to_search_skeleton",
    ]) );
set("item_func",([
    "skeleton":"to_look_skeleton",
    "paper": "to_look_paper",
    ]) );
set("exits",([
             "leave":Deathland"/holyplace/f03",
             ]));
reset();
}

int to_look_skeleton()
{
     write( 
           "似乎這個駭骨已經放在這個地方很久了. 而上面有著一張\n"           
           "符咒(incantation paper)附在上面.\n"
           );
     return 1;        
}

int to_look_paper()
{

    write(
          "一張附於駭骨身上的怪異符咒.\n"
          );
    return 1;      
}

string to_search_skeleton()
{
     object paper,*item,player;
     int i;
     
     player=this_player();
     item=all_inventory(player);
     write( 
            "你搜查駭骨, 沒有什麼大發現, 除了那張奇怪的符咒外, 沒有其\n"
            "他特別的事物. 於是你就把那張符咒給撕下來\n"
          );
     write(
           "然而當你拿到了符咒之後, 你發現駭骨上又多了一道相同的符咒.\n"
           "令人覺得這符咒似乎有種很強的魔力."
           );
     for(i=0;i<sizeof(item);i++) 
       if ( (string)item[i]->query("name")=="Incantation paper of Lock") 
         return "\n";
     paper=new(Object"/letter03");
     paper->move(this_player());
     return "\n";            
}

