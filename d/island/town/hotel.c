//#pragma save_binary

#include "../island.h"
#include <money.h>

inherit ROOM;
inherit SELLER;

void create()
{
    ::create();
    set_short("龍門客棧");
    set_long(@C_LONG
這是家新近成立的客棧，由於老闆算準了這兒大有可為，故在此開了
家店。由於此處來來往往的商旅特別多，此處變成了龍蛇雜處之地。客棧
內充斥著掌櫃的吆喝聲及客人的喧鬧聲，但也有些人完全無視喧囂，只是
安靜的坐在角落的座位上獨酌，看來此處確實是個是非之地。
C_LONG
             );
      set("exits",([
            "north" : ITOWN"town04"]) );
      set("light",1);
      set("no_monster",1);
      set_inventory( ({
                       ({ IOBJ"wheet", 20 , 20}),
                       ({ IOBJ"lu-wei", 15 , 15}),
                       
        }) );
        set( "objects",([ "lizardman" : "/d/island/hole/monster/valor",
                          "boss" : IMON"boss" ]) );
        reset();

}      
void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_look","look");
  return;
} 
int do_search()
{
 tell_object(this_player(),"正當你在探頭探腦的時候，櫃檯裡的夥計跟你說道：『想買東西的話\n，看看價目表(list)就好了！』\n");
 return 1;  
}
int do_look(string arg)
{
  if (!arg || arg != "list") return 0; 
  show_menu();
  return 1;
}                     
 
void reset()
{
    room::reset();
    seller::reset();
}
              