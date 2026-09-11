
#include "zeus.h"

inherit ROOM;
int x;
void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，前面消失的鐵軌現在又出現在地上，鐵軌是南北
向的，四周用了許多木條固定，這裡就是礦工們工作的地方了，通道的左側
好像有崩塌過的痕跡，留下了一些奇奇怪怪的小洞，而整個房間正瀰漫著一
股淡淡的油氣味道．．
CLong
);
set("item_desc",(["hole":"@@query_look"]) );
set("exits",([
             "south":ZROOM"/keyroom02"
             ]));
set("objects",([
              "overseer":ZMOB"/overseer",
              "miner#1":ZMOB"/miner02",
              "miner#2":ZMOB"/miner02"
              ]));

reset();
}     
void init()
{
add_action("to_throw","throw");
   }
   
int to_throw(string s)
{     string s1,s2;
      object obj1,obj2;
   if (!s){
           return notify_fail("你想丟些什麼?  throw <somthing> to <location>\n");
          }       
   sscanf(s,"%s to %s",s1,s2);
   if (s1){
           if(!(obj1=present( s1,this_player())))
              return notify_fail("你根本沒這樣東西！\n");
           if(s1!="paper")    
                return notify_fail("你有病啊？這麼大的東西，怎麼丟得進去！！\n");
           }               
   if((!s2)||s2!="hole")
                return notify_fail("丟!丟!丟到哪裡去?\n");
                
    if(this_player()->query_temp("paper/light")){                        
    write("你將千里火往小洞裡一丟，引起了一聲巨響！左方的牆壁被炸開了．\n");
    write("地上出現了一塊發亮的金屬．\n");
    obj1->remove();
    obj2=new("/d/eastland/goomay/obj/fire_key.c");
    obj2->move(this_object());
    this_player()->set_temp("magic/paper",0);
    tell_room(environment(this_player()),(
    this_player()->query("c_name")+"將千里火丟進洞裡，引起了一場爆炸，幸好你
    及時閃避沒有受到任何傷害，煙幕中好像有什麼東西一閃一閃的．\n"),
    this_player());
    return 1;
    }else{
          write("你把未點燃的千里火丟到洞裡去了！\n");
          this_player()->set_temp("magic/paper",0);
          tell_room(environment(this_player()),(
          "不知道"+this_player()->query("c_name")+"將什麼丟到洞裡！\n"),
          this_player());
          obj1->remove();
          return 1;
          }
}
int query_look()
{
   if(this_player()->query_temp("magic/paper")){ 
write("你仔細一瞧，果然有一個洞．這個小洞看起來烏漆漆的，裡面似乎是個洞穴，
不時地流出一些氣體，原來油氣味道就是由這裡發出來的．偶而你還會看到
一點點亮光，不知道裡面藏著什麼寶物！\n");
}
else
   {write("一個很平常的小洞，看不出由啥特別的地方．\n");
   }
   }        