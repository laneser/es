#include "../../story.h"

inherit MONSTER;
#define MAX_HP(x)   (int)x->query("max_hp")
#define HP(x)       (int)x->query("hit_points")
#define NAME(x)     (string)x->query("name")
#define CNAME(x)    (string)x->query("c_name");
void create()
{
    ::create();
    set_level(17);
    set_name( "Wizard Doctor", "巫姑" );
    add( "id",({"doctor","wizard"}) );
    set_short( "藥師 巫姑");
    set_long(@LONG
你眼前所見的是一位面目慈祥和藹可親的老太婆。巫姑是城中醫術最高明的大夫，
她善用巫術替人治病，其中並且參雜了中醫的療法，雖然兩者不太相干系，但成效
之大，卻出乎意料之外。巫姑現在正持著金針替人治病，雖然病患堪多，她卻絲毫
沒有任何疲倦的樣子，精神還頗好哩！如果你有任何地方不舒服或許可以要求她替
你看看(diagnose)。
LONG
            );
    set("unit","位");
    set("race","巫師");
    set("age",79);
    set("gender","female" );
    set("alignment",800);
    set("weight",600);
    set("wealth/gold",70);
    set_temp("be_joke",2);
    set_perm_stat("str",19);
    set_perm_stat("dex",27);
    set_perm_stat("kar",30);
    set_perm_stat("int",28);
    set_perm_stat("pie",23);
    set("hit_points",600);
    set("max_hp",600);
    set("max_fp",400);
    set_natural_armor(12,39);
    set_natural_weapon(52,8,17);
    set_skill("dagger",90);
    set_skill( "bandage",90);
    set_skill("anatomlogy",100);
    set_skill("dodge",75);
    set_skill("parry",75);
    set("special_defense", ([ 
       "all": 200,"none":40,"energy":20]) );
    set("aim_difficulty",
    (["critical":50,"vascular":70,"ganglion":70,"weakest":30]) );
    set("stun_difficulty",90);
    wield_weapon(SWWEA"wiz_dagger1");
    equip_armor(SWARM"wiz_cloth2");
    equip_armor(SWARM"wiz_gloves1");
    equip_armor(SWARM"wiz_helmet2");
    set( "tactic_func", "my_tactic" );
    set( "inquiry", ([
          "lucky":"@@ask_dog",
       "diagnose":"@@ask_diagnose",
              "1":"@@ask_clot",
           "clot":"@@ask_clot",
           "止血":"@@ask_clot",
              "2":"@@ask_poison",
       "depoison":"@@ask_poison",
           "驅毒":"@@ask_poison",
              "3":"@@ask_bandage",
        "bandage":"@@ask_bandage",
           "包紮":"@@ask_bandage",
      "disappear":"@@ask_disappear",   
              "4":"@@ask_disappear",
    ]) );
}        
void ask_dog(object asker)
{
write(@LONG
巫姑說道：lucky?莫非你問的護國師孫女養的小白狗？不曉得咩，前幾天還有
　　　　　看到她去溜狗。
LONG
   );
}
int hate()
{
   if ( this_player()->query_attacker() ) {
      write("\n巫姑生氣地說：哼，無恥小賊，既然敢 Pk 我就休想要我替你看病！\n\n");
      return 1;
   }         
   return 0;
}
int ask_diagnose( object asker )
{
   if ( hate() ) return 1;
   command(sprintf("look %s",NAME(asker)));
   write(@LONG

巫姑咳嗽幾聲然後說道：要看病可以，不過先請付些費用。以下
　　　　　　　　　　　是我的公訂價格。
    
          *****************************************************
          **			                	     **
          **   1.止血(clot)           :  15   GOLD (次) 。   **
          **   2.驅毒(depoison)       :  25   GOLD (次) 。   **
          **   3.包紮(bandage)        :  6    GOLD (次) 。   **
          **   4.惡靈驅散(disappear)  :  100  GOLD (次) 。   **
          ** 				                     **
          *****************************************************

不知您要那一樣？
LONG
   );
}

void ask_bandage( object asker )
{
     if ( hate() ) return ;
     command(sprintf("look %s",NAME(asker)));

     if ( !asker->debit("gold",6) ) { 
        write("巫姑說道：對不起，你錢不夠，包紮一次需要 6 GOLD。\n");
        return;
     }  
     if ( HP(asker)>MAX_HP(asker) ) { 
        write("巫姑說道：好孩子，你好好的嗎。\n");
        return ;
     }
     if ( asker->query_temp("bandaged") ) { 
        write("巫姑說道：好孩子，你似乎被別人包紮過了喲。\n");
        return ;
     }
     if ( !present("bandage",this_object()) ) {
        write("巫姑說道：唉，我身上的一些繃帶已經用光了，你可以給我一些嗎？\n");
        return ;
     }
     command(sprintf("bandage %s",NAME(asker)) );
     write("巫姑說道：嗯，包紮好了，你活動一下看傷口處是否妥當。\n");
     command(sprintf("pat %s",NAME(asker)));
     return ;
}
void ask_poison( object asker )
{
     if ( hate() ) return ;
     command(sprintf("look %s",NAME(asker)));
          
     if ( !asker->debit("gold",25) ) {
        write("巫姑說道：對不起，你錢不夠，驅毒一次需要 25 GOLD。\n");
        return;
     }
     if ( !asker->query("conditions/simple_poison") ) {
        write("巫姑說道：好孩子，你身上並沒有任何中毒的跡象。\n");
        return ;
     }
     write(@LONG

巫姑用金針往你中毒的部位一刺，緩緩流出傾盆的黑血，
當黑血漸漸呈現紅色時，巫姑朝著你的患部喃喃自語，瞬
間，你的傷口愈和了，只留下一個小小的疤痕！

巫姑說道：好孩子，你所中的毒業已清除了。
LONG
    );   
    asker->delete("conditions/simple_poison");
    command(sprintf("pat %s",NAME(asker)));
    return ;    
}
void ask_clot( object asker )
{
     if ( hate() ) return ;
        command(sprintf("look %s",NAME(asker)));
          
     if ( !asker->debit("gold",15) ) {
        write("巫姑說道：對不起，你錢不夠，止血一次需要 15 GOLD。\n");
        return;
     }
     if ( !asker->query("conditions/bleeding") ) {
        write("巫姑說道：好孩子，你身上並沒有流血咩。\n");
        return ;
     }
     write(@LONG

巫姑用她手中的金針在你的傷口處縫了幾針，然後
對著你傷口處喃喃自語，瞬間，你再也不流血，而
患部只留下一個小小的疤痕。

巫姑說道：嗯，好了，已經幫你過血了。     

LONG
     );     
     command(sprintf("pat %s",NAME(asker)));
     asker->delete("conditions/bleeding");
     return ;     
}
void ask_disappear( object asker )
{
     object damn;
     if ( hate() ) return ;
     command(sprintf("look %s",NAME(asker)));
             
     if ( !asker->debit("gold",100) ) {
        write("巫姑說道：對不起，你所帶的錢不夠，驅散一次需要 100 GOLD。\n");
        return;
     }
     damn=present("evil damn",asker);
     if ( !damn ) {
        write("巫姑說道：好孩子，你並沒有被下詛咒的現象。\n");
        return ;
     }
     damn->remove();
     write(@LONG
                                                                      
只見巫姑一陣手足舞蹈，口中唸唸有詞，好像起乩一樣 ...

過了良久，巫姑慢慢回神說道：嗯，你再也沒有被邪靈附身了！

LONG
     );
}
int my_tactic()
{
     object victim;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if ( victim->query("conditions/herb_apply") ) { 
        victim->delete("conditions/herb_apply");
        set("conditions/herb_apply",({ 10, 7, 30 }));
     }
     switch( random(20) ) {
     case 0..8 : set("aiming_loc","critical");
                 break;
     case 9..10: set("aiming_loc","ganglion");
                 break;
     case 11..17:
                 if ( victim->query("conditions/bleeding") ) 
                     set("aiming_loc","weakest");
                 else set("aiming_loc","vascular");
                 break;
     default:
            set("aiming_loc","vascular");
            break;
     }                                             
     return 0;          
}                  