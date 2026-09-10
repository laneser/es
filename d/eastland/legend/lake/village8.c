#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("井底");
        set_long( 
@LONG
噗的一聲，你從水底探頭而出，深吸了一口氣，心想好險，差點就被奄死了。
你攀住手邊的巖塊，好奇地往周圍打探了一下，發現你身處井底。井水泌涼，井壁
上光滑乾淨，鮮有青苔，看來定是口常被使用的水井。你想附近就應該有人煙，也
許大叫救命就會有人聽得見，順便拉你出井。
LONG);
    set( "light",1);
    ::reset();
}

void init()
{
   add_action("do_shout","shout");
}

int do_shout(string arg)
{
    
   object player,env;
  
   if ( !arg || arg!="救命" && arg!="help" ) return 0;
   player=this_player();
   env=find_object_or_load(LAKE"village9");
   call_out("help1",3,player,env);
   return 0;
}
void help1(object player,object env)
{     
   if ( !present("woman",env) ) {
     tell_object(player,"你等了一會兒，\n竟然給它沒有人，『口年口年』！\n");
     return ;
   }
   tell_object(player,"\n你聽到井邊一陣騷動，拋下了一根繩索．．．．\n");
   player->move_player(LAKE"village9","SNEAK");
   tell_object(player,"你伸手一拉，攀了上來．．．．．\n");
   tell_room(env,@LONG

井邊正在洗衣服的媽媽桑大喊著說：『麼壽喔！沒事亂跑到井裡~!@#$%^&*....』

LONG);
   return;
}     


