#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "Sleeping man", "昏睡在路邊的人" );
    add( "id",({"man"}) );
    set_short( "昏睡在路邊的人");
    set("no_attack",1);
    set_long(@C_LONG
一個喝醉酒倒在路邊的人。他滿身酒臭味,令你全身作嘔,不過他似乎知道
某些事情,叫醒他說不定會吐露什麼喲!!!
C_LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",18);
    set("gender","man" );
    set("alignment",1000);
    set("weight",300);
    set("hit_points",1);
    set("max_hp",1);
}        

void init()
{ add_action("do_slap","slap");}

int do_slap(string arg)
{
   object ob1;
     
   if ( arg=="man" ){ 
     if (this_player()->query_temp("button")){
        tell_object(this_player(),
"他說道:他媽的,吵什麼吵,再吵我打你喔。\n");
     }
     else {                                                            
       tell_object(this_player(),
"\n     唉喲,蝦米大代志啦,人家睡得好好的!!說著他反身想睡,可是\n"
"又爬了起來,說道:哦,原來是我家那支母老虎叫你來的喔,拿去吧。\n\n"
       );
       ob1 = new(DITEM"button");
       ob1->move(this_object());
       this_player()->set_temp("button",1);
       command("give "+(string)ob1->query("name")+" to "+
       lower_case((string)this_player()->query("name")));
     } 
   }
     return 1;
}