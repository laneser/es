#include <mudlib.h>

inherit ROOM;
void create()
{
     ::create();
}
void init()
{
    add_action("do_stun","stun");
}
int do_stun(string arg)
{
   if (this_player()->query("class")!="monk"){
       tell_object(this_player(),"你要幹什麼?\n");
       return 1;
   }
   if (!this_player()->query_attackers()){
       tell_object(this_player(),"你沒在戰鬥中，找不到對手在哪裡!\n");
       return 1;
   }
   tell_object(this_player(),set_color(
        " *** 你全神貫注，開始要找機會施展你點穴的神技 ! *** \n","HIC"));
   call_out("recover",6,this_player());
   return 1;
}
void recover(object obj)
{
   if (environment(obj)==this_object()) {
      tell_object(obj,"該死,你誤點了自己的穴道!!!\n");
      obj->block_attack(10);
      obj->set_temp("msg_stop_attack","(  你被點住了穴道動彈不得 !!  )\n");
   } else tell_object(obj,"你的戰鬥結束了，不需要點穴了!\n");
}
