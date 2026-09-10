
#include "../echobomber.h"

inherit Deathland+"/dwarf/daemon/muse";
inherit ROOM;

void create()
{
	::create();
    set("light",1);
    set_short("Muse Fountain","謬思泉");
    set_long(@Long
Long
,@CLong
你能夠清楚的感覺到一種神聖的力量圍繞於泉水的四周, 那就是傳說中的謬思泉了.
關於謬思泉的傳說實在太多了, 而它目前就在你的面前. 在這個寧靜的地方你可以暫時拋
開俗世的煩惱, 靜靜地享受這個地方所給你的舒適的感覺. 
CLong
    );
   set("muse_color",2);
   set("item_func",([
       "fountain":"look_fountain",
       "muse":"look_fountain",
       ]) );
   
   set("exits",([
       "south":Deathland"/dwarf/muse14",
       "southeast":Deathland"/dwarf/muse24",
       ]) );
   reset();
}

void init()
{
     add_action("to_drink","drink");
     add_action("to_fill","fill");
}

int to_fill(string str)
{
    if (!str || str=="") return 0;
    if ( str=="water" || str=="fountain")
    return fill_muse_water(this_player(),query("muse_color"));          

}

int to_drink(string str)
{
    if (!str || str=="") return 0;
    if ( str=="water" || str=="fountain")
      write(
      "你確定要喝下這泉水嗎??這泉水你完完全全不知道它的性質與成份....\n"
      "但是如果你已經瞭解它的特性的話, 就喝吧! 否則沒有人會保證有甚麼\n"
      "事情會發生.\n"
      "用 < drink <color>_muse_water > 去喝下這泉水吧!!\n"
      );
    else if (str=="green_muse_water")  {
       drink_muse( query("muse_color") , this_player() );
       
       }
    else return 0;
    return 1;   
}

int look_fountain()
{ 
    write("一座與一般的泉水沒有兩樣的謬思泉, 也許是這個地方給你的感覺, 也許是\n"
          "一股神聖的力量從泉水中散發而出, 你能確定這個地方就是謬思泉. \n"
          "這泉水看起來清涼潔淨, 只是它的顏色是一種詭異的綠(green)色.........\n"
          );
    
    return 1;
}

