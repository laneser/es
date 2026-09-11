
#include "zeus.h"

inherit ROOM;
int dog;
void create()
{
  ::create();
  set_short("竹橋");
  set_long(@CLong
這是一座看起來簡單卻很堅固的竹橋 (bridge)，好像可以承受極大的重量
．兩旁的水以非常快的速度流著，橋下還張著一個網子(net)，可是不知道這有
什麼用，地上的鐵軌到了這裡似乎已經到達終點．橋邊有一條小路通往橋下．　
CLong
);
set("exits",([
             "south":ZROOM"/m_enter",
             "north":ZROOM"/mine01",
             "down":ZROOM"/port",
             ]));
set("item_desc",(["net":
"一張破破的網子，似乎不是用來抓魚的，也許你可以找人問問他的作用是什麼．\n",
"bridge":@BB
一座簡簡單單的竹橋，走在上面搖搖晃晃的，感覺滿舒服的．你想搖搖(shake)
它試試看堅不堅固嗎?
BB
]));
  reset();
 }
 void reset()
 {
    ::reset();
    dog=1;
 }
void init()
{
   add_action("do_shake","shake");
}
int do_shake(string str)
{  object ob;
   if(!str||str!="bridge"){
   write("你想幹什麼???\n");
    return 1;
   }
   
   if(dog){
   ob=new(ZMOB"/dog");
   ob->move(this_object());
   dog=0;
   return 1;
   }
   else {
   write("這橋早就被搖得破破爛爛的了！再搖下去就斷了！\n");
   return 1;
   }
   
}   
   