#include "../story.h"

inherit ROOM;
int on_war=0;
void create()
{
        ::create();
	set_short("血瀑布");
	set_long( @LONG
這裡就是傳說中的血瀑布，籠罩在一團紅霧裡。在瀑布上流著得是鮮血，飛瀉
而下猶如一抹紅色的匹練，在昏暗毫無亮光之下，益發顯得更加駭人。傳說中，血
瀑布具有重生的能力，你只要把□體埋(bury)在這裡，那□體就會有機會得到新的
生命，令人不可思議。
LONG
	);
	set( "exits", ([ 
       	      "crack" : SAREA"vhole2" 
        ]) );
	reset();
}
void init()
{
   add_action("do_bury","bury");
}
void resetwar()
{
    on_war=0;
}
void trigger()
{
   find_object_or_load(WMOB"war")->start_war();
}
int do_bury(string arg)
{
   object player,corpse;
   string name,pname;
   if ( !arg ) return notify_fail("你要埋什麼東西？\n");
   player=this_player();
   corpse=present(arg,player);
   if ( !corpse ) return notify_fail("你沒有那樣東西。\n");
   name=corpse->query("c_name");
   pname=player->query("c_name");
   if ( ( !corpse->query("chicorpse") ) || on_war ) {
      tell_object(player,sprintf("你把%s埋在血瀑布裡卻沒發生任何事情。\n",name));      
      tell_room(this_object(),sprintf("%s把%s埋在血瀑布裡卻沒發生任何事情。\n",pname,name),player);
      corpse->remove();
      return 1;           
   }
   corpse->remove();
   on_war=1;
   tell_object(player,sprintf("你埋在血瀑布裡的%s突然發生了變化！\n\n",name));     
   tell_room(player,sprintf("%s理在血瀑布裡的%s突然發生了變化！\n\n",pname,name),player);
   call_out("count1",5,name);
   return 1;
}
void count1(string name)
{
   tell_room(this_object(),set_color(sprintf(
     "忽然間，血瀑布裡的%s活了過來！你心裡閃過莫名的恐懼...\n\n",name),"HIR"));
   call_out("count2",10);
}
void count2() 
{  
   trigger();
}
