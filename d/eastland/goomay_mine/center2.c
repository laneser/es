
#include "zeus.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("礦坑大廳");
  set_long(@CLong
這是座十分寬闊的地方，有許多的矮凳子，可見此地是礦工們休息的地方，
而整個房間被開鑿成八卦型，宛如蜘蛛網的中心點，是控制礦坑內各出口的重要
樞紐，要到達礦坑的任何角落，都必須經過此地．
CLong
);
   

set("exits",([
             "west":ZROOM"/center1",
             "north":ZROOM"/center3",
             "southeast":ZROOM"/mine12",
             ]));

reset();
}
void init(){
add_action("south_wall","push");
      }
int south_wall(string ob)
{     

string him;
      him =(string)this_player()->query("c_name"); 
      if(!ob||ob !="south wall") 
      { write("你使盡了吃奶的力氣，可是它一動也不動!\n");
        tell_room(environment(this_player()),(
        "你發覺"+him+"很努力地往牆壁撞去，你懷疑他的腦袋是不是裝草的！\n"),
        this_player());
      return 1;      
        }
      else
      {
      
      write("\n你用力往牆壁一推，突然整個身子陷入牆裡.\n");
      tell_room(environment(this_player()),(
      him+"突然從牆邊消失了！\n"),
      this_player());
      this_player()->move_player(ZROOM"/control.c","SNEAK");
      } 
      return 1;
 }