#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("津鳴城北門");
    set_long(@LONG
這裡是魔族的皇城－津鳴城的北門，由這兒仰望都城的部份，心中不由
得為魔族的先進文明感到佩服不已。整座城是由數不盡的樑柱架構而成，或
斜插，或橫伸，亦或直挺；雖然令人無法理解，卻不會感到不協調，相反的
，還讓人忍不住的想開口讚美呢！
LONG
            );
    set("light",1);
    set("exits",([
        "south":CITY"r2",
        "north":AREA"way2"]) );
    
    set("objects",([
        "soldier#2":TMOB"soldier",
        "soldier#1":TMOB"soldier"]) );
  
    set("pre_exit_func",([
            "south":"do_say"]));
    set_outside("island");
    reset();
}

void init()
{ add_action("do_say","say"); }

int do_say(string arg)
{
   if( !present("soldier"))
   return 0; 
   
   if( !arg ){
   write("\n魔族士兵伸手攔下你：喂！等一下，報上通行密碼，不然不準過去！\n\n");
   return 1;}
   
   if( arg != "芋頭蕃薯") {
   write("\n士兵生氣的大吼罵道：喂！你在吱吱嗚嗚什麼？這裡只准說密碼！\n\n");
   return 1; }
  
   if( !this_player()->query_explore("island#2") ) {
   write("\n士兵惡狠狠地瞪你一眼，說道：不要以為我不知道你密碼是騙來的 !\n");
   write("士兵大喊道：再不走的話我要砍人嘍 !!\n");
   return 1;}
               
   write("\n士兵和緩的說：嗯！！可以確定你不是武士堡或蜥蜴窩的奸細，好，進去吧！\n\n");
   tell_room( environment(this_player()),
     "士兵催促著"+this_player()->query("c_name")+"趕快通過！\n",
     this_player() );
   this_player()->move_player(CITY"r2","SNEAK");
   tell_room( environment(this_player()),
     this_player()->query("c_name")+"快步的走了過來！\n",
     this_player() );
   return 1;
}   
   
    
