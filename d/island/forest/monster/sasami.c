#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "Princess Sasami", "砂紗美" );
    add( "id",({"sasami","princess"}) );
    set_short( "砂紗美公主");
    set_long(@LONG
砂紗美是樹雷王家的第二公主。她是個非常可愛的小女孩，和她那任性的姊姊
完全不同。傳說她具有與船穗溝通的能力，所以，你千萬不要小看她哦；魎皇鬼是
砂紗美的寵物，可是不知道跑到哪兒去了，如果你答應幫她找回來的話，她會告訴
你有關魎皇鬼(luoky)的詳細情形的！
LONG
            );
    set("unit","位");
    set("race","daemon");      
    set("class","healer");
    set("age",10);
    set("gender","female" );
    set("alignment",800);
    set("weight",300);
    set("wealth/gold",150);
    set_perm_stat("str",18);
    set_perm_stat("dex",15);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set_perm_stat("pie",30);
    set("time_to_heal",30);
    set("hit_points",500);
    set("max_hp",500);
    set("spell_points",200);
    set("max_sp",200);
    set_natural_armor(55,27);
    set_natural_weapon(45,0,15);
    set_skill("dagger",70);
    set_skill("anatomlogy",90);
    set_skill("dodge",70);
    set_skill("block",80);
    set_skill("tactic",80);
    set("tactic","assault");
    set("special_defense",(["evil":60,"energy":0,"fire":50,"cold":50,
                            "electric":50,"none":20]) );
    set("aim_difficulty",
    (["critical":-20,"vascular":80,"ganglion":20,"weakest":80]) );
    set("aiming_loc","weakest");

    set("inquiry",([
        "luoky":"@@ask_luoky"]) );
    set("exp_reward",20000);
        
    wield_weapon(TWEP"key2");
    equip_armor(TOBJ"shield1");
    equip_armor(TOBJ"arms");
    equip_armor(TOBJ"leggings");
}

int accept_item(object player,object ob)
{
    if( !ob || !(ob->query("give_to_sasami")) ) return 0;
    if( (string)ob->query("winner") != (string)player->query("name") ){
      tell_room(environment(),
"紗砂美有點失望的說：謝謝你把它送回來，但還是請你幫我對那位好心人士說聲謝謝！\n"
"紗砂美公主把心愛的寵物關回籠中！\n");
      return 1;
      }  
    if( (int)player->query_quest_level("find_luoky") < 1) {
    tell_object(player,"謝謝你為我找回魎皇鬼，謝謝！\n");
    tell_room(environment(),
       "砂紗美公主把心愛的寵物關回籠中！\n");
       player->finish_quest("find_luoky",1);
    tell_object(player,
      "你已經完成了這個任務，你得到1000點經驗值\n");
       player->gain_experience(1000);
       ob->remove();
       return 1;
     }
     tell_object(player,"再次感謝您的幫忙！謝謝！！\n");
     tell_room(environment(player),
       "砂紗美以微笑對"+player->query("c_name")+"的熱心表示感謝！！\n"); 
     return 1;
 } 
 
 void ask_luoky()
 {
    write(@ALONG
魎皇鬼嗎？它是我心愛的寵物，長得有點像小兔子，兩隻耳朵長長的，叫聲很像
貓；我昨天帶它到院子去玩的時候，它突然就走失了，你願意幫我把它找回來嗎？
啊？我忘了告訴你，要抱它的話，一定要拿蘿蔔給它才能抱哦，不然他會咬你哦！
謝謝你！！^_^
ALONG
        );
	return ;
}
void die()
{
    object killer;
    killer = query("last_attacker");
    killer->set_temp("get_key",1);
    ::die();
    return;
}        
