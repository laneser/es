#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "地下水道" );
   set_long(@ANGEL
你來到一個地下水道，雖然是在地下，但空氣卻是很清新，讓你不會
有氣悶的感覺，而且你發現這裡地上蠻乾淨的，似乎有人居住在裡面，你
突然有一種奇怪的感覺，覺得這裡牆壁(wall)和其他地方不一樣．    
ANGEL
   
         );
	set( "light",0);
	set("item_desc",([
	"wall":"一個顏色很灰暗的牆壁，上面有幾道刮痕\n"
	]));
	set("search_desc",([
	"wall":"@@to_search_wall"
	]));
        set( "exits", ([
                "east" :MR"tube02"
                ]) );
         reset();                     
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if(!arg || arg!="gate")
       return notify_fail("你要進去哪裡?\n");
   write("你小心翼翼的走入這個通道，發現裡面居然有個房間\n");
   this_player()->move_player(MR"tube04","SNEAK");
   return 1;
}       

string to_search_wall()
{
         this_player()->set_explore("island#12");
  return "當你仔細搜索牆壁時，發現裡面隱藏著一個通道(gate)\n"
         "你可以試著進入(enter)\n";
}            
