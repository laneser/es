#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("內城南門");
    set_long(@LONG
這裡是樹雷王家居住處－內城的南門，由這兒仰望都城的部份，心中不
由得為魔族的先進文明感到佩服不已。整座城是由數不盡的樑柱架構而成，
或斜插，或橫伸，亦或直挺；雖然令人無法理解，卻不會感到不協調，相反
的，還讓人忍不住的想開口讚美呢！
LONG
            );
    set("light",1);
    set("exits",([
        "south":CITY"r6",
        "north":CITY"inway4"]) );
    
    set("objects",([
        "soldier#2":TMOB"warrior",
        "soldier#1":TMOB"warrior"]) );
  
    set("pre_exit_func",([
            "north":"do_say"]));
    set_outside("island");
    reset();
}

void init()
{ add_action("do_say","say"); }

int do_say(string arg)
{
   if( !present("warrior"))
   return 0; 
   
   if( !arg ){
   write("\n魔族戰士伸手攔下你：喂！等一下，報上通行密碼，不然不準過去！\n\n");
   return 1;}
   
   if( arg != "很久很久以前有一個老公公和一個老婆婆") {
   write(@ALONG
    戰士生氣的大吼罵道：不知道密碼去問將軍，不要在這裡竊竊私語
，小心我海Ｋ你一頓哦！
ALONG
         );
   return 1; }
   
   if( !this_player()->query_explore("island#3") ) {
   write("\n戰士凝望著你的眼睛，過了一會兒，說道：\n");
   write("\n不要以為隨隨便便打聽到了密碼就能混進去，還不快滾 !!\n");
   return 1;}
   
   write("\n戰士和緩的說：嗯！！可以確定你不是武士堡或蜥蜴窩的奸細，好，進去吧！\n\n");
   tell_room( environment(this_player()),
     "戰士招手示意"+this_player()->query("c_name")+"趕快通過！\n",
     this_player() );
   this_player()->move_player(CITY"inway4","SNEAK");
   tell_room( environment(this_player()),
     this_player()->query("c_name")+"畏畏縮縮的走了過來!\n",
     this_player() );
   return 1;
}   
   
    
