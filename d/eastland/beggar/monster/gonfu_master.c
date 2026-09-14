#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name( "gonfu master","項長老" );
        add ( "id", ({ "master","gonfu"}) );
        set_short("項長老" );
        set("unit","位");
        set_long(@C_LONG
項長老位居丐幫的傳功長老,平時掌管兩項鎮幫神功『降龍十八掌』和『打狗棒法
』。項長老三十多年前為了逃避仇人的追殺而穩居到『薪膽村』來,日子一久忘了
自己叫什麼,只記得姓項而己, 所以大家都稱呼他為『項長老』。前些時候丐幫內
亂,項長老因平靖有功,被升為二大長老之一。別看他老態龍鍾的樣子,他可也是很
厲害的喲。 
C_LONG
        );
        set("alignment",1200);
        set("wealth/silver",700);
        set("gender","male");
        set("race","human");
        set("hit_points",450);
        set("force_points",400);
        set("max_hp",450);
        set("weight",710);
        set_perm_stat("str",22);
        set_perm_stat("dex",18);
        set_perm_stat("int",10);
        set_perm_stat("kar",15);
        set_natural_weapon(30, 12, 25);
        set_natural_armor(20,20);
        set( "special_defense", ([ "all": 20, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":100,"vascular":30,"ganglion":20 ]) );
        set( "stun_difficulty",50 );
        set_skill("dodge",55);
        set_skill("parry",65);
        wield_weapon(DWEAPON"blunt");
        equip_armor(DARMOR"broken_cloth");
        set( "inquiry", ([
                  "chan":"@@ask_chan",
                  "war":"@@ask_war"
        ]) );
        set("tactic_func","my_attack");
}
void ask_chan( object asker )
{
     if ( asker->query_temp("unary_asked") ) {
        tell_object( asker,
           "項長老說道:喔, 你要打聽全副幫主的消息? 最近他沒有和我聯絡, 所以我也不知\n"
           "           道他到底在什麼地方。對了,他最喜歡喝酒了,你可以去有酒的地方找\n"
           "           找看。 如果你找到他之後順便幫我勸勸他,說他老子是自作孽不可活\n"
           "           ,叫他千萬不可步他老子的後塵,他老子也就是十多年前的叛變(war)\n"
           "           弟子--全執祥,不然像他這麼一個大好英雄的前程會白白給毀了。\n"
        );
        asker->set_temp("gonfu_asked",1);
        return ;
     } 
        tell_object( asker,
           "項長老搖搖頭說道:我不知道。\n");
}
void ask_war( object asker )
{
write(@C_LONG        
項長老嘆道:唉,十多年前,本幫中有一位頗為聰明的弟子,由於他千方百計想得到幫主之位
           ,不惜以外面的力量,打擊本幫,頓時幫內遭到一場空前的活劫;那時,死傷無數
           ,骸骨堆積成山鮮血流成河,幫內精英消失殆盡,所幸在 幫主 震八方英明的領
           導之下,擊潰敵人無數,才能挽救現在的局面。但為了安撫不安的叛變的弟子,
           不得已委以那位弟子的遺孤重任,所幸,那遺孤也英雄了得,替幫內整頓得好生
           興旺。那遺弧也就是現在的全副幫主,那時的叛變弟子自是他父親--全執祥。
           最近,全副幫主不知道從那裡打聽到全執祥的消息,唉,如果沒有人好好替他開
           導,以他熱血情操,真不知....唉,希望不要再有十多年前的慘事發生。
C_LONG
     );
}            

int my_attack()
{
    object victim,wea1,wea2;
    
    if( !(victim = query_attacker()) ) return 0;

    if( random(30) < 2 ) { 
      tell_room( environment(this_object()),
          "項長老使出了『打狗棒法』之『絆』字訣把"+
          victim->query("c_name")+"絆倒了!!\n",victim);
      tell_object( victim,
          "項長老使出了『打狗棒法』之『絆』字訣把你給絆倒了!!\n");         
      victim->receive_damage(15);
      victim->block_attack(8);
      victim->set_temp("msg_stop_attack",
          "(  你被絆倒了,瞬間無法攻擊 !!  )\n");
      return 1;                     
    } else if ( random(30) < 4 ) {
        tell_room( environment(this_object()),
           "項長老使出了『打狗棒法』之『黏』字訣......\n");
           victim->receive_damage(10);
           wea1=victim->query("weapon1");
           wea2=victim->query("weapon2");
           if (wea1) wea1->unwield(1);
           if (wea2) wea2->unwield(1);
           return 1;
    } return 0;
}

