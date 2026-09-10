#include "../legend.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "hermit", "隱者" );
    add( "id",({"hermit"}) );
    set_short( "隱者");
    set_long(@LONG
一位年約八、九十歲的老人，他隱居在這裡己經有四、五十年了，因為時間太久，
也就忘了原來姓什名什，只知道他在五十多年前是位活人無數的神醫，至於他為什
麼會待在這裡，卻沒人知道究竟。隱者站在這裡，聆聽泉水聲，他似乎若有所思，
想得出神了，一點也沒發覺到你的存在，看他悠閒自在的樣子，相信你也不忍心去
打擾他。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","healer");
    set("age",89);
    set("gender","male" );
    set("alignment",6000);
    set("weight",600);
    set_perm_stat("str",20);
    set_perm_stat("dex",26);
    set_perm_stat("int",28);
    set_perm_stat("kar",30);
    set("hit_points",550);
    set("max_hp",550);
    set_natural_armor(55,50);
    set_natural_weapon(28,6,8);
    set_skill("dodge",80);
    set_skill("parry",70);
    set_skill("dagger",90);
    set_skill("anatomlogy",100);
    set("special_defense", ([ "all": 50,"none":30]) );
    set("aim_difficulty",
    (["critical":65,"vascular":20,"ganglion":70,"weakest":65]) );
    set("stun_difficulty",90);
    wield_weapon(LWEAPON"ice_needle");
    set("chat_chance",10);
    set( "att_chat_output", ({
        "隱者道：可惡！竟敢打擾我的清靜，看我好好教訓你！\n"
    }) );
    set("inquiry", ([
           "美容":"@@ask_buty",
         "beauty":"@@ask_buty",
     "兜率彌陀珠":"@@ask_ball",
           "ball":"@@ask_ball",
         "三珠樹":"@@ask_tree",
           "tree":"@@ask_tree"
    ]) );
    set("tactic_func","my_tactic");
}        
void ask_buty(object asker)
{
write(@C_LONG
隱者說道：你要美容喔？你已經這麼美了，還要更美喔？會不會太貪心咩？
你向他解釋了半天．．
隱者說道：你如果要更美的話可以去找傳說中的「朱果」，「朱果」在那兒我是不知
　　　　　道，不過書中有記載，「朱果」生長在「三珠樹」上，約每千年開花一次
　　　　　五百年才結一次果，相當珍貴無比。但是，在「三珠樹」旁有神獸看守，
　　　　　並不是那麼容易取得，切記切記。

隱者說完後，繼續在一旁靜思。　　　　   

C_LONG
      );
}
void ask_ball(object asker)
{
write(@C_LONG
隱者說道：兜率彌陀珠?
隱者說道：一個很好的東西啊，你不會用？記著，你只要 ( use_lifeball )
　　　　　就可以了。
C_LONG
      );
}
void ask_tree(object asker)
{
write(@C_LONG
隱者說道：一般來說，心地極善良的人才有緣看到「三珠樹」，如果你覺得不夠
　　　　　善良，不妨到沼澤裡多砍幾隻壞的怪物。如果，你有緣看到「三珠樹」
          ，不妨搖搖樹幹，說不定會有「朱果」掉下來。
C_LONG
      );
}
int my_tactic()
{
     object victim;
     int select;
          
     if (!(victim= query_attacker())) return 0;
     select=random(20);
     if ( select > 13 ) set("aiming_loc","critical");
     else if ( select > 11 ) set("aiming_loc","ganglion");
     else if ( select > 3 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
          if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
          else set("aiming_loc","vascular");
     }
     return 0;
}