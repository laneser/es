
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The serect room","隱密的小房間");
    set_long(@Long
Long
,@CLong
你目前位於一個隱密的小房間裡,這裡充滿詭異的氣氛,似乎這裡有著一股奇異的力量.
西邊的牆上有著一個按鈕(button),沒有人知道按下去的後果會如何?
CLong
    );
    set("c_item_desc",([
        "button":"一個鮮紅色的按鈕,似乎提醒人們不要去碰它.\n",
                ]) ); 
    set("exits",([
                "up":Deathland"/village/v24",
             ]));
    set("objects",([
        "guardian":Monster"/guard06.c",
                   ]) );
    create_door("up","down",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"一個小小的木門",
               "c_name":"小木門",
               "name":"small wooden door",
               "desc":"a small wooden door",
               ]) );
    ::reset();
}

void init()
{
   add_action("do_push","push");
}

int do_push(string str)
{
   if (!str||str!="button") return 0;
   if (!present("guardian"))
      {
       write("一道強光筆直地穿過你的身體.\n\n\n\n"
             "你的靈魂離開了你的身體\n");
       this_player()->set_temp("block_command",1);
       
       call_out("recover",15,this_player());        
       say("當"+this_player()->query("short")+"按下了按鈕後,一道強光刺穿了他的身體.\n"
           "然後"+this_player()->query("short")+"就倒地不起了.\n");       
       return 1;
      }
   else 
      {
      write("守衛說:不要碰那個按鈕.\n");
      say(this_player()->query("short")+"試著按下按鈕但被守衛阻止.n");
      return 1;   
      }
}

int recover(object who)
{
   who->set_temp("block_command",0);
   tell_object(who,"慢慢地,你的靈魂已經回到你的身體之中.\n"
                   "而且似乎一種特別的力量注入你的身體裡面.\n"
                   );
   who->set_explore( "deathland#25" );
   who->set_temp("deathland_magicwall",1);                
   return 1;
}
