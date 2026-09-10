#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "patient","受傷者" );
	set_short("受傷者");
	set_long(@C_LONG
這是一位受傷沈重的人，他已陷入昏迷狀態；在他全身上不下千百個創口，每個創
口都深及見骨，傷口處還泊泊地流著大量的鮮血，然而，你卻發現，每個傷口似乎
都有經過熟練的包紮，慢慢地不再流著鮮血。你細看，他的嘴唇黑的嚇人，看來是
中了某種劇毒！但見他口中喃喃自語，似乎極需要你的幫忙。
C_LONG
	);
	set("unit", "名" );
        set("race","human");
        set("gender","male");
        set("max_hp",10000000);
        set("hit_points",1);
        set("no_attack",1);
        set( "inquiry", ([
             "help":"@@ask_help",
             "trouble":"@@ask_help",
             "poison":"@@ask_help",
             "幫忙":"@@ask_help",
             "麻煩":"@@ask_help",
             "劇毒":"@@ask_help",
        ]) );
}
void ask_help( object asker )
{
write(@C_LONG
受傷者說道：吾人到這裡探險，不小心被「文蛛」所傷，因而受傷沈重。
　　　　　　傷口處已被路過的高人包紮了，但高人卻束手無策關於我所
　　　　　　中之毒，唉，沒想到我就要死在這裡了．．
　　　　　　　
C_LONG
      );
}
int accept_item(object me, object item)
{
    string my_name,item_name;
    
    my_name=(string)me->query("name");
    item_name=(string)item->query("name");
    if ( !item->query("drink_liquid")) {
       write("受傷者不要你這個東西。\n");    
       command("give "+item_name+" to "+my_name);
       return 1;
    }    
    item->remove();
    write (@LONG       
受傷者喝下你帶來給他的「文蛛」毒液，登時，他身上所中的毒全解除了！
受傷者說道：感謝你解除我身上所中之毒，有一事不敢不告訴，那就是－－
　　　　　　這裡的叢林被人施之法術，不知究竟的人是無法走出去的，只
　　　　　　要你遇到「文蛛」時快折回西走，往南，再向東，那就可以脫
　　　　　　困了。
LONG
    );
//    if ((int)me->query_quest_level("patient")<1 ) {
  if ((int)me->query("quests/patient")<1 ) {
      
    write (@LONG
        
  [ 由於你熱心地解除了受傷者的所中的毒，因而意外地獲得到 2000 點的經驗]    
    
LONG     
    );
//    me->finish_quest("patient",1);
    me->set("quests/patient",1);
    me->gain_experience(2000);
    }
    return 1;
}                  