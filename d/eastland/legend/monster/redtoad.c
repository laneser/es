#include "../legend.h"
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"
inherit MONSTER;

void create()
{
  ::create();
  set_level(19);
  set_name("crimson toad", "莽牯朱蛤");
  add( "id", ({ "toad" }) );
  set_short("莽牯朱蛤");
  set_long(
    "一隻小小的蛤蟆，身長不過兩寸，身體通紅勝血，兩顆眼珠發出閃閃金光。嘴\n"
    "巴微張，頦下鼓膜震動，就是一聲江昂．聲似牛鳴，卻更為淒厲，恍若平地一\n"
    "聲雷，若非親眼見到，絕難相信如此大小的蛤蟆居然發的出這麼大聲響．\n"
    );
  set( "race", "amphibia" );
  set( "unit", "只" );
  set( "alignment", -3000 );
  set( "exp_reward",50000 );
  set_natural_armor( 80, 30 );
  set_natural_weapon(80,55,65);
  set( "max_hp", 1000 );
  set( "hit_points", 1000 );
  set_skill("dodge",100);
  set_perm_stat( "int", 30 );
  set_perm_stat( "dex", 30 );
  set_perm_stat( "kar", 40 );
  set( "killer", 1 );
  set( "time_to_heal", 50 );
  set("aim_difficulty",([ "critical":50,"ganglion":100 ]) );
  set("stun_difficulty",70);
  set("special_defense", (["all":75,"divine":10,"none":30]) );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "頭部", "身體", "舌頭", "前腳", "後腳" }) );
  set_c_verbs( ({ "%s伸出血紅色的舌頭卷向%s" ,
                  "%s猛地跳起，一頭撞向%s",
                  "%s對%s噴出一口毒氣"
                  }) );
}

int emit_poison()
{
  object *victim;
  int i,j;

  if( random(20)>6 || !(victim= query_attackers()) ) return 0;
  
  i=sizeof(victim);
  if ((j=random(14))>10) {
    tell_object( environment(this_object()),
      "\n突然，莽牯朱蛤躍起丈餘，江昂一聲，吐出一團淡淡的紅霧射中了你....\n\n"
    );
    while(i--) {  
      (CONDITION_PREFIX + "simple_poison")->apply_effect( victim[i], 5, 20 );
      (CONDITION_PREFIX + "slow")->apply_effect( victim[i], 5, 5 );
      (CONDITION_PREFIX + "weak")->apply_effect( victim[i], 5, 5 );
      victim[i]->receive_special_damage("acid",50);
      report(this_object(),victim[i]);
    }   
    return 1;
  }
  else if (j>5) {
    
    tell_object( environment(this_object()),
      "\n只見一團紅光在眾人四周飛竄，你一不小心就被咬到了，傷口流出汩汩的鮮血..\n\n"
      ); 
    while (i--) {
      (CONDITION_PREFIX + "simple_poison")->apply_effect(victim[i],5,15 );
      (CONDITION_PREFIX + "bleeding")->apply_effect(victim[i],5,20 );  
      victim[i]->receive_special_damage("acid",30);
    }   
    return 1;  
  }
  else {
    tell_object( environment(this_object()),
      "\n莽牯朱蛤，江昂，江昂的叫個不停，喚下數十道雷擊，嚇的你動彈不得....\n\n"
      );
    while (i--) {
      victim[i]->block_attack(4);   
      victim[i]->set_temp("msg_stop_attack",
        "你被轟隆轟隆的雷聲嚇的動彈不得！\n");
      victim[i]->receive_special_damage("acid",20);  
    }
    return 1;
  }
}
void die()
{
   object ball,killer;
   ball=new(LITEM"lifeball");
   ball->move(environment(this_object()));
   tell_room(environment(this_object()),
      "莽牯朱蛤死前從腹中吐出一顆散出五彩光芒的珠子!\n");
   if ( killer=query("last_attacker") ) killer->add_temp("mobs",10);
   ::die();    
}