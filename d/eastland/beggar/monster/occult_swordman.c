#include "../dony.h"

#define NAME(x)     (string)x->query("c_name") 

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "occult swordman Fan", "風飛雪" );
    add( "id",({"swordman","fan","man"}) );
    set_short( "謎樣劍客 風飛雪");
    set_long(@LONG
在你眼前的是一位傷勢很重的謎樣劍客。他全身上下不下千百個傷口,傷口處還在
泊泊著流著許多鮮血,鮮血把他的衣襟都弄溼了, 他的背上還有條深一□長約尺餘
的創痕,一看就知道剛才和別人狠狠的惡鬥一番。風飛雪原本是去尋仇的, 無奈仇
家太過厲害,許多招式往往施展到一半就被破了,還被仇家重創,只好退到這裡來養
傷以等待適當的機會。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","knight");
    set("age",18);
    set("gender","male" );
    set("alignment",6500);
    set("weight",800);
    set("wealth/gold",250);
    set_perm_stat("str",25);
    set_perm_stat("dex",22);
    set_perm_stat("kar",21);
    set_perm_stat("int",28);
    set("hit_points",580);
    set("max_hp",580);
    set_natural_armor(29,17);
    set_natural_weapon(36,15,30);
    set_skill("shortblade",80);
    set_skill("dodge",90);
    set_skill("parry",85);
    set("special_defense", ([ "all": 40,"none":30]) );
    set("aim_difficulty",
    (["critical":35,"vascular":90,"ganglion":75,"weakest":45]) );
    set("stun_difficulty",80);
    wield_weapon(DWEAPON"seven_sword");
    equip_armor(DARMOR"fun_cloak");
    equip_armor(DARMOR"fun_turban");
    equip_armor(DARMOR"fun_gloves");
    equip_armor(DARMOR"fun_boots");
    equip_armor(DARMOR"fun_belt");
    set( "chat_chance", 10 );
    set( "att_chat_output", ({
           "風飛雪怒道:你是專門欺負受傷的人嗎?\n",
           "風飛雪狂笑道:哈哈哈,你以為我是那麼好欺負的嗎?\n",
           "風飛雪道:哼,跟我同歸於盡吧!!!!\n"
    }) );
    set( "tactic_func", "my_tactic" );
    set( "inquiry", ([
         "enemy":"@@ask_enemy",
    ]) );
}        
void ask_enemy()
{
write(@C_LONG
風飛雪嘆道:唉,你能幫我報仇嗎?我的仇人是一個東瀛忍者.....
C_LONG
    );
}
int my_tactic()
{
    object env,me,victim;
    string my_name,vic_name;
        
    victim=query_attacker();
    me = this_object();
    my_name=NAME(me);
    vic_name=NAME(victim);
    env = environment(me);
                                      
    if ( !victim ) return 0;
    
    switch( random(45) ) {
    case 1..3:
       victim->receive_special_damage("evil",30);
       tell_object(victim,"\n"+
         my_name+"對你大喝道:「一文字流巖斬」!!!\n\n");                                          
       report(this_object(),victim);
       tell_room(env,"\n"+
         my_name+"對"+vic_name+"大喝道:「一文字流巖斬」\n\n",victim);
       return 1;
    case 4..5:
       victim->receive_special_damage("sleet",30);
       tell_room(env,
         my_name+"把手中的劍舞成一團白光,忽地破白光而出.....\n\n");
       report(this_object(),victim);
       return 1;
    case 6:
       victim->receive_special_damage("divine",30);
       tell_room(env,  
         my_name+"面色慘然,使出了一招『天地同儔』....\n\n");
       report(this_object(),victim);
       return 1; 
    default :
         return 0;
    }
}
