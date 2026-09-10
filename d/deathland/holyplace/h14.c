// Deathland/holyplace/h14.c
// Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

int search_slit;
void create()
{
	::create();
  set_short(" A strange place","陰暗的虛無飄渺處");
  set_long(@Long
Long
,@CLong
一處陰暗的地下世界,四處的黑影無聲無息地向你侵襲而來.這裡的寂靜令人感到害怕,
讓你不自主的想要發出一些聲音.沒有風聲,沒有水聲,甚至你無法聽到自己的腳步聲,你不
禁懷疑自己處在一個虛無的地方.你的視野越來越小,似乎你的眼睛被一些黑色的\"霧\"擋住
了視線.你必須隨時提防從黑暗中跑出的危險,那些黑暗的霧中很明顯藏著邪惡的根源.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );

set("exits",([
             "north":Deathland"/holyplace/h10",
             "northwest":Deathland"/holyplace/h15",
             "south":Deathland"/holyplace/h09",
             ]));
set("pre_exit_func",([
    "south":"to_south",
    ]) );   

set("exit_suppress",({"south",}));    
    
reset();
}

void init()
{
   call_out("notice_exit",1,this_object(),this_player(),0);
}

string to_look_fog()
{
     return can_read_chinese() ?
            "是霧嗎?你懷疑著,你能很清楚地看到一些懸浮粒子飄散在你的周圍.\n"
            "\或許是一種邪惡的物質,你能感覺到有著邪惡的成份參雜其中.這\n"
            "地方的\"霧\"似乎特別的大,\或許有一些東西並不是顯而易見的.\n"
            "你必需讓你的眼睛適應這個地方的環境.\n":
            "need work.\n"; 
}

void notice_exit(object ob1,object ob2,int depth)
{
  
     if (depth<10) {
       if (environment(ob2)==ob1) {
         if ( depth==0 )
           tell_object(ob2,
             "這地方似乎有些奇怪. 但你目前不太能瞭解那是什麼.\n"
             );
         if (depth==4)
           tell_object(ob2,
             "這地方一定有些不尋常, 待久一點也許會有更多的發現.\n"
             );
         call_out("notice_exit",1,ob1,ob2,depth+1);
         }
       else return ;
       } 
     else    
     if (environment(ob2)==ob1)
     tell_object(ob2,
                 "由於你待在這裡夠久,你的眼睛已經逐漸地適應這個地方,\n"
                 "這時你發現在南方的一處巖壁竟然是假的.\n"
                 );
     ob2->set_temp("echo_holy",0x01);   
     return; 
}

int to_south()
{
    if ( (int)this_player()->query_temp("echo_holy") & 0x01  )    
      return 0;
    else {
      write("你想去撞壁嗎?\n");
      return 1;
      }
            
}

