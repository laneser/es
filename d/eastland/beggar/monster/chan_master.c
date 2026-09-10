#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "a drunk man", "倒在桌上的醉漢" );
    add( "id",({"man"}) );
    set_short( "倒在桌上的醉漢");
    set("no_attack",1);
    set_long(@C_LONG
一個倒在桌上的醉漢。
C_LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",300);
    set("chat_chance",2);
    set("chat_output",({
         "醉漢道:店小二,拿酒來。\n"
    }) );
                                    

}        
int accept_item(object me, object item)
{
      string name,my_name;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
                  
      if (name!="chan letter")
         return 0;
//     if( (int)me->query_quest_level("dony1") ) {
       if ( me->query("finish_dony") ){
         tell_object( me,"醉漢說道:謝謝。\n");
         item->remove();
         return 0;
      }   
      if ( ( item->query("master") ) != my_name ) {
         tell_object( me,
           "醉漢說道:你這是打那兒來的東西啊?\n");
         command("give chan letter to "+my_name);
      }
      else {
         tell_object( me,
           "醉漢接過你的信件...........\n");
         item->remove();
         call_out("recover1",15,me);
      }
      return 1;
}
void recover1(object me)
{
     object ob1;
     
     tell_object( me ,
        "醉漢激動地說道:這.這這...是..是是......\n"
        "醉漢嘆道:唉,全然錯了。看了我父親給我的信之後,我才知道原來他老人家是咎由自取\n"
        "         ,這跟我所想的完全不一樣,我本想救他老人家出來,然後殺了震八方替他報\n"
        "         仇可是,幸虧有你帶來的信,否則........................................\n"
        "         煩麻你把這根打狗棒送還給幫主,並且跟他老人家說我太對不起他了無顏見他\n"
        "         ,最後我只有一個心願,吾之女兒還請你代嫁。\n");
     ob1=new(DITEM"dog_blunt");
     ob1->set("master",me->query("name"));
     ob1->move(this_object());
     command("give dog blunt to "+me->query("name"));   
     tell_object( me ,
        "醉漢說完之後就不見了。\n");
     this_object()->remove();   
}      