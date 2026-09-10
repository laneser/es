#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("八音澗");
        set_long( 
@LONG
沿著古木小徑尋著泉水聲音走到這兒，抬頭一望，是條南北走向的山澗，一縷
飛瀑凌空而降，宛如一道丈來寬的匹練，銀光閃閃，橫卷直瀉，注入了山澗之中；
瀑布和泉聲相和，盤迴跌落，如奏宮商，不絕於耳。忽而水流涓涓，輕聲泠泠似絲
竹輕彈；忽而水聲浩浩如同金石交鳴。每當降雨之日，八音澗上有靈雨飄空，銀花
四射，飛舞而下；下有珠飛玉滾，翠浪奔騰，端的是上天造物之驚奇，令人讚歎。
LONG);
    set( "light",1);
    set( "exit_suppress", ({
          "west" }) );
    set("exits",([
          "west":LAKE"village4",
    ]) );
    set("objects",([
       "hermit":LMONSTER"hermit"
    ]) );
    ::reset();
}

void init()
{
   add_action("do_dive_down","dive");
   add_action("do_search","search");
}
int do_search()
{
   tell_object(this_player(),
        "這裡沒有什麼東西，不過你可以試著往池子(pool)潛潛(dive)看。\n");
   return 1;
}
int do_dive_down(string arg)
{
  int probability;
  object player,env;
  string name;
  
  player=this_player();
  if (!arg||arg!="pool") {
    tell_object(player,"你想潛到哪裡去。\n");
    return 1;
  }
  env=environment(player);
  name=player->query("c_name");
  tell_object(player,"你深吸一口氣，以狗爬式潛下八音澗飛瀑下的水潭.......\n");
  tell_room(env,sprintf(
    "%s深吸一口氣，以狗爬式潛下八音澗飛瀑下的水潭.......\n",name),player);
  probability=(int)player->query_skill("swimming")/(int)player->query_level();
  if ( probability+random(5) >7 ) {
     player->set_temp("block_command",1);
     call_out("recover1",7,player);
     return 1;
  }
  tell_object(player,"你不暗水性，狼狽地爬了上來跑到「月到風來亭」小憩。\n\n");
  tell_room(env,sprintf(
    "%s狼狽地爬了上來，什麼收穫也沒有跑到「月到風來亭」小憩。\n\n",name),player); 
  player->move_player(LAKE"village6","SNEAK");
  return 1;
}
void recover1(object player)
{
   player->delete_temp("block_command"); 
   tell_object(player,"\n鶩地！水潭裡一股吸力把你卷向一個地方....\n\n\n\n");
   player->move(LAKE"village7","SNEAK");
}  



