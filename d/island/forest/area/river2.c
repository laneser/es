#include "../tsunami.h"
#include <conditions.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("河中");
    set_long(@LONG
在這潺潺的小河中看，只覺得一切都好乾淨、好清晰，頭頂上的光透過
波浪，映在底下的沙地上，使人感覺彷佛置身於塵囂之外，那另一個未曾探
索過的世界一般。這令人流連的境地，讓你幾乎忘了要呼吸了！咦～這裡似
乎怪怪的耶！
LONG
            );
    set("exits",([
        "up":AREA"upriver2",
        "north":AREA"river"]) );

    set_outside("island");
    set("underwater",1);
    set("objects",([
        "turtle":TMOB"turtle" ]) );
    reset();
}

void init()
{
UNDERWATER->apply_effect(this_player(),3,2);
add_action("do_search","search");
}

int do_search(string str)
{
   if( !str || str != "here"){
   write("你要找什麼呢??\n");
   return 1;
   }
   write(@ALONG
   你正想搜索可疑之處時，突然一道漩渦將你捲進一個小洞中...
ALONG
        );   
   tell_room( environment(this_player()),
   this_player()->query("c_name")+
     "在這裡翻來翻去，突然間，出現一個馬桶洞大小的漩渦把他吸走了...\n",
     this_player() );
   this_player()->move_player("/d/island/8,8.island","SNEAK");
   tell_room( environment(this_player() ),
   "當你在洗腳時，突然"+this_player()->query("c_name")+"從你跨下鑽了出來...\n"
   ,this_player() );
 return 1;
}    