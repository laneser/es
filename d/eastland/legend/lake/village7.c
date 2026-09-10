#include "../legend.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("「碧水寒潭」");
        set_long( 
@LONG
颼！你進入「碧水寒潭」裡，極寒冷的潭水不斷地湧向你全身的毛細孔，一股
冰冷的氣流從你頭頂灌入直達腳底，你彷佛身處冰窖裡，不禁倒抽了一口氣。在潭
裡，你不住地抖動身體，不時浮出水面，卻發現越來越難受，你身體的機能警告著
你快離開快離開不然就來不及了。
LONG);
    set( "light",1);
    set("underwater",1);
    set( "exit_suppress", ({
         "up"}) );
    set("exits",([
            "up":LAKE"village5"
    ]) );
    ::reset();
}

void init()
{
   UNDERWATER->apply_effect(this_player(),4,2);
   add_action("do_dive_down","dive");
   add_action("do_search","search");
}
int do_search()
{
   tell_object(this_player(),
     "這裡沒有什麼東西，不過你可以試著往下(down)潛潛(dive)看。如果你游泳的技能不夠，那還是往上(up)離開好了。\n");
   return 1;
}
int do_dive_down(string arg)
{
    
  int probability;
  object player,env;
  string name;
  
  player=this_player();
  if (!arg||arg!="down") {
     tell_object(player,"你想潛到哪裡去。\n");
     return 1;
  }
  if ( player->query_temp("have_dive") ) return 1;
  player->set_temp("have_dive",1);
  env=environment(player);
  name=player->query("c_name");
  tell_object(player,"你深吸一口氣，潛下「碧水寒潭」.......\n");
  tell_room(env,sprintf("%s深吸一口氣，潛下「水潭寒潭」.......\n",name),player);
  probability=(int)player->query_skill("swimming")/(int)player->query_level();
  if ( probability+random(5) >7 ) {
     player->set_temp("block_command",1);  
     call_out("recover1",7,player);
     return 1;
  }
  tell_object(player,"忽然一股極大的壓力迎面而來讓你幾乎暈了過去..\n\n");
  player->delete_temp("have_dive");
  player->receive_damage(10);
  return 1;
}
void recover1(object player)
{
   player->delete_temp("block_command"); 
   player->delete_temp("have_dive");
   tell_object(player,"\n鶩地！水潭裡一股吸力把你卷向....\n\n\n\n");
   player->move(LAKE"village8","SNEAK");
}  



