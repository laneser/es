
#include <zeus.h>

inherit ROOM;
int x;
void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，前面消失的鐵軌現在又出現在地上，鐵軌是南北
向的，南邊是一道深長的拱門，透出一股奇怪的感覺，門旁邊還掛著一個醒
目的牌子(sign)，從門裡偶而可以聽到嘩啦嘩啦的聲音．
CLong
);   
set("item_desc",(["sign":@SIGN
   ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
   ＊　　　　　　　　　　　　　　　　　　　＊
   ＊　　機關重地！閒雜人等請勿再進！　　　＊
   ＊　　　　　　　　　　　　　　　　　　　＊
   ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
SIGN
     ]));
set("exits",([
             "south":ZROOM"/mine13",
             "northwest":ZROOM"/center2"
             ]));
set("pre_exit_func",([
                      "south":"to_pass",
                      ]) );             
reset();
}
void reset()
{
  ::reset();
    x=1;
}    
int to_pass()
{   object obj;
    int damage_hp;
    int initial_hp;
    int final_hp;
    int bounus;
    
    
   damage_hp = (int)this_player()->query("max_hp");
   initial_hp = (int)this_player()->query("hit_points");
   bounus = (int)this_player()->query_perm_stat("dex");
   final_hp = (initial_hp - (damage_hp/3) + bounus);
   if(present("pigeon")){
         x=0;
         obj=present("pigeon");
         obj->remove();
         tell_room(environment(this_player()),
         "鴿子好像受到驚嚇的樣子，突然振翅飛走了．\n",
         this_player());
                  } 
   if(present("arrow")){
         x=1;
         obj=present("arrow");
         obj->remove();
         tell_room(environment(this_player()),
         "響鈴箭～碰～～一聲爆炸了，只剩下一堆的飛灰隨風飄散！\n",
         this_player());
                 }
    if(x){
    write("**當你走入拱門時，一陣陣的暗器，如滿天花雨般向你襲來，你雖然用盡所\n");
    write("\n**有的身法，仍然無法避免被打傷！！\n\n");
    this_player()->set("hit_points",final_hp);
    return 0;    }
    else{
    x=0;
    return 0;    }
 }