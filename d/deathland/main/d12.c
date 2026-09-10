
#include "../echobomber.h"
inherit ROOM;
void create(){
      ::create();
       set("light",1);
 set("short","深淵的南邊");
 set("long",@Long_description
到了這裡,風勢仍然一樣的強勁,但是那團霧(fog)卻是依舊滯留著,而且有
逐漸擴散的趨勢,你已經無法看到附近的地形了,但你仍必須小心翼翼的站著以
免被強勁的風勢吹進那個看不見的深淵.現在你必須鼓起極大的勇氣走入霧中,
否則只有回頭了.
Long_description
          );
set("item_desc",([
    "fog":@Fog
一團黑霧,你無法清楚地看見霧中究竟有什麼東西.但是你能感覺到霧中似乎有
股奇異的力量.假如你的好奇心十分強烈的話,或許你應該走進霧中去探險,但是
你不能確定你能活著走出來.
Fog
                  ]) );
 set("exits",(["east":Deathland"/main/d10",
              ]));

}

int init()
{
add_action("walk_fog","walk");
add_action("walk_fog","enter");
}

int fog_1(object ob1)
{
  tell_object(ob1,@FFF
一種神奇的力量把你推了回來
FFF
     );
  ob1->move_player(Deathland"/main/d12","SNEAK","");
}

int walk_fog(string str)
{
if (!str||str!="fog") {
  write("為何不試著走入霧中?\n");
   return 1; }
else {
   if (this_player()->query_stat("karma")>=35) {
   call_out("fog_1",4,this_player());
   this_player()->move_player(Deathland"/fog/fog1","SNEAK","");
   }
   else
   write("當你走入霧中後,由於缺乏一些運氣,你差點跌入深淵,"
         "於是你又只好退了回來.\n");
     }
this_player()->set_explore( "deathland#3" );
return 1;
}
