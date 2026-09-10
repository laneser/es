#include "../../takeda.h"
#include "/include/move.h"
#include <daemons.h>
#include "conditions.h"
#include "stats.h"

#define C_NAME(x)     (string)x->query("c_name") 
#define NAME(x)       lower_case((string)x->query("name"))        

inherit "d/eastland/liang_shan/monster/chi_yu_group";

void create()
{
    ::create();
      set_level(18);
      set_name( "evil scholar", "邪惡書生" );
      add ("id", ({ "scholar" }) );
      set_short( "邪惡書生");
      set("unit","位");
      set("alignment",-1300);
      set("weight",400);
      set_long(query("c_name")+"帶著小偷專用的萬用小刀。\n");
      set( "alt_corpse", "NONE" );
      set( "moving", 1 );
      set( "speed", 40 );
      set_perm_stat( "dex", 23 );
      set_perm_stat( "str", 15 );
      set_perm_stat( "int", 30 );
      set_perm_stat( "kar", 20 );
      set_skill( "parry", query_level()*4 );
      set_skill( "sword",query_level()*4 );
      set_skill( "anatomlogy", query_level()*3 );
      set( "aiming_loc", "ganglion" );
      set("chi_yu_group",1);                   
      set("max_hp",440);
      set("hit_points",440);
      set("natural_defense_bonus",20);
      set ("natural_weapon_class1", 10);
      set ("natural_armor_class", 40);
      set ("special_defense",(["fire":-20,"cold":-20]));
      set ("gender", "male");
      wield_weapon("/d/deathland/weapon/sword03");
      set_temp("be_joke",10);
      set("class","scholar");
      set("max_sp",1000);
      set("spell_points",1000);
      set("max_fp",500);
      set("force_points",500);
      set("couple",1);
      set("stun_difficulty",40);
      set( "alt_corpse", "NONE" );
      set("tactic","flank");
      set("scholar_gonfu/song",40);
      set("attack_skill","scholar/song");
      set("embattle",
          ([ "four" : 1, "three" : 1, "two" : 1 ]));
      set( "tactic_func", "my_tactic" );
      command("party form");
}        

int can_help( object ob )
{
   if( ob->query_attacker() ) return 0;
   if( ob->query("couple")) return 1;
   return 0;
}
void make_angry(object obj)
{
   object ob1,ob2,ob3,*all,env;        
        
    if( query("have_party") ) return ;
    if( random(8) > 1 ) return ; 
    env=environment(obj);
    tell_room(env,C_NAME(obj)+
      "大喝:「注意，這裡有敵人喔....」\n"
      "一大群蛇人不知從那兒跑了出來，把你團團圍住... \n\n");
    set("have_party",1);
    set("party_num",4);
    set_temp("embattle_busy",0);
    ob1=new(TMONSTER"chi_yu/healer");
    ob1->move(env);
    ob2=new(TMONSTER"chi_yu/knight");
    ob2->move(env);
    ob3=new(TMONSTER"chi_yu/mage");
    ob3->move(env);
    ob1->set("master",obj);
    ob2->set("master",obj);
    ob3->set("master",obj);
    ob1->set_temp("leader",obj);
    ob2->set_temp("leader",obj);
    ob3->set_temp("leader",obj);
    ob1->add_temp( "protectees", ({ obj }) );
    ob2->add_temp( "protectees", ({ obj }) );
    ob3->add_temp( "protectees", ({ obj }) );
    all=obj->query_temp("party_members");
    all=all+({ob1,ob2,ob3});
    obj->set_temp("party_members",all);
    obj->add_temp( "protectors",({ob1,ob2,ob3}));
}

int my_tactic()
{
     object *all,*couples,victim,ob1,ob2,ob3;
     int i,members;     
     string name;
     
     if (!(victim= query_attacker())) return 0;
     name=lower_case(NAME(victim));
     couples = filter_array( all_inventory(environment(this_object())),
        "can_help", this_object() );
     for( i=0; i<sizeof(couples); i++ ) 
            couples[i]->kill_ob(victim);
     if ( this_object()->query("spell_points")<200 ) 
          this_object()->set("spell_points",1000);
     
     
     make_angry(this_object());
     if (!query_temp("embattle_busy")){
     switch( query("party_num") ) {
     case 2:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「結兩儀微塵陣」!\n");
               command("embattle two at "+name); 
               return 0;
     case 3:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「結天地人三才陣」!\n");
               command("embattle three at "+name);
               return 0;
     case 4:
               tell_room(environment(this_object()),
                  C_NAME(this_object())+"喝道:「結四象璇璣陣」!\n");
               command("embattle four at "+name);  
               return 0;
     default :
            return 0;
     }}
       if (random(10) > 1) return 1;
       switch (random(4)) {
       case 0:
         tell_object(victim,set_color( "你見到地面突然裂開，大地精靈從中衝了出來向你施展它的必殺技：十字鎖喉反扣。\n","HIM",victim));
         tell_room(environment(this_object()),set_color("你見到地面突然裂開，大地精靈從中衝了出來向"+victim->query("c_name")+"施展它的必殺技：十字鎖喉反扣。\n","HIM",victim),victim);
         victim->block_attack(2);
         victim->set_temp("msg_stop_attack", "（ 你現在被大地精靈扣住，動彈不得，無法攻擊 ）\n");
         return 0;
       case 1:
         tell_object(victim,set_color("突然晴天一聲霹靂，火精靈挾著雷霆之勢從天而降，火精靈把口一張，從嘴裡向你射出一團火□。\n","HIR",victim));
         tell_room(environment(this_object()),set_color("突然晴天一聲霹靂，火精靈挾著雷霆之勢從天而降，火精靈把口一張，從嘴裡向"+victim->query("c_name")+"射出一團火□。\n","HIR",victim),victim);
         victim->receive_special_damage("fire",20);
         return 0;
       case 2:
         tell_object(victim,set_color( "你感覺到一道劍氣直射而至，劍魂化成一把寶劍在空中飛舞著，突然，寶劍一氣化三元，三把寶劍劍鋒向你吐出紅藍綠三色劍芒。\n","HIW",victim));
         tell_room(environment(this_object()),set_color( "你感覺到一道劍氣直射而至，劍魂化成一把寶劍在
         空中飛舞著，突然，寶劍一氣化三元，三把寶劍劍鋒向"+victim->query("c_name")+"吐出紅藍綠三色劍芒。\n","HIW",victim),victim);
         BLEEDING->apply_effect(victim,5,5);
         return 0;
       case 3:
         tell_room(environment(this_object()),set_color("你見到天空一朵烏雲飄來，水精靈從中飄了出來，水精靈用手觸摸"+this_object()->query("c_name")+"的傷口之後，水精靈又隨著烏雲飄走了。\n","HIB",victim));
         this_object()->receive_healing(20);
         return 0;
      default: return 0;
      
    }
    return 1;
  }

void die()
{
  object killer;
  if ( !killer = query("last_attacker") ) {
  ::die(1);
  }
  else
  write(query("c_name")+"化為一道青煙，消失在空氣中...\n");
  ::die(1);
}
