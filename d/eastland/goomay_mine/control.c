
#include <zeus.h>

inherit ROOM;
int number;
void create()
{
  ::create();
  set_short("機關房");
  set_long(@CLong
這裡是礦坑內的機關重地，是段氏一族為了保護這個維持他們生活的礦坑，所
建的機關室，這裡控制了礦坑內所有的重要機關，你看到一個拉桿(lever) 發出油
油的亮光，必定是時常開啟的機關．房間上方有一個不大的籠子，裡面發出一些奇
怪的聲音，籠子前有一個小小的洞(hole)．
CLong
);
set("item_desc",(["lever":
"這是一根由鐵所鑄成的拉桿，推動它不知道會有什麼後果．\n",
"hole":"一個小小的通道，上面還有些許的鳥糞！\n"
]) );

set("exits",([
             "north":ZROOM"/center2"
             ]));
set("objects",([
    "mine_master":ZMOB"/mine_master",
    ]) );
reset();
}
void reset()
{
   ::reset();
   number=1;
}

void init()
{
  add_action("do_pull","pull");
  add_action("do_push","push");
  if(this_player()) this_player()->set_explore("eastland#16");
}
void to_fly(int x)
 {   object obj;
     if(x){ 
     tell_room(environment(this_player()),(
     "你聽到啪～啪～的聲音，突然有一隻鴿子從東邊牆角的小洞飛了出去！\n"
                                   ));
     
                                   
     obj=new(ZMOB"/pigeon");
     obj->move(ZROOM"/mine12");   
     tell_room( environment(obj),
     "你聽到啪～啪～的聲音，一隻可愛的鴿子飛了進來！\n",
     this_player());                              
//     this_player()->set_temp("mine/damage",1);                                    
               }
     else{
     tell_room(environment(this_player()),(
     "突然一隻箭帶著令人心悸的聲音，從東邊小洞射出．\n"
                                  ));
     
     obj=new(ZOBJ"/arrow");
     obj->move(ZROOM"/mine12");
     tell_room(environment(obj),
     "一陣鬼哭神嚎的聲音後，一隻箭就插在你的腳邊，彷佛在警告著你！！！\n",
     this_player());
//     this_player()->set_temp("mine/damage",0);
        }
}
int do_pull(string str)
{
   if(!str||str!="lever"){
   write("你要拉什麼??????\n"); 
   return 1;
                         }
      if(number==0){
      write("這拉桿已經被拉到底了！\n");
      return 1;
            }             
   if (!present("master")) {
   write("你聽到～喀～一聲，似乎啟動了什麼機關.\n");
   tell_room(environment(this_player()),(
      "當"+this_player()->query("c_name")+"拉動杆子時，發出了一陣聲響\n"),
             this_player() );
   call_out("to_fly",1,1);
   number=0; 
   return 1;
                           }
   else
      {write("段老大說:你幹什麼!!!不要動那個拉桿!!!!\n");
      tell_room(environment(this_player()),(
      this_player()->query("c_name")+"想要拉拉桿時，被段老大罵了一頓．\n"),
              this_player() );  
   return 1;
   }
}
int do_push(string str)
{
   if(!str||str!="lever"){
   write("你要推什麼??????\n"); 
   return 1;
                         }
      if(number==1){
      write("這拉桿已經被推到底了！\n");
      return 1;
            }             
   if (!present("master")) {
   write("你聽到～喀～一聲，似乎啟動了什麼機關.\n");
   tell_room(environment(this_player()),(
      "當"+this_player()->query("c_name")+"推動杆子時，發出了一陣聲響\n"),
             this_player() );
   call_out("to_fly",1,0);
   number=1;
   return 1;
                           }
   else
      {write("段老大說:你幹什麼!!!不要動那個拉桿!!!!\n");
      tell_room(environment(this_player()),(
      this_player()->query("c_name")+"想要推拉桿時，被段老大罵了一頓．\n"),
              this_player() );
   return 1;
   }
}
