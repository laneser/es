#include "../oldcat.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "worker", "掃地工" );
        set_short( "掃地工");
        set("unit","位");
        set_long(@LONG
掃地工的職責就是把神殿打掃乾靜，讓各位大德能好好的在神殿中修行，
不要小看了掃地工的工作，能把地掃得一塵不染是非常不容易的事，不信的話
你自己去試試看。
LONG
        );
        set("alignment",1000);
        set("wealth/silver",50);
        set("gender","male");
        set("race","dwarf");
        set("max_hp", 600);
        set("hit_points", 600);
        set("special_defense", ([ "all" : 45, "none" : 40 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50 ]) );
        set_perm_stat("str", 24);
        set_perm_stat("dex", 28);
        set_perm_stat("pie", 18);
        set_perm_stat("kar", 23);
        set_natural_weapon( 15, 7, 18 );
        set_natural_armor( 58, 30 );
        set_skill("dodge",100);
        set_skill("blunt",100);
        set("chat_chance",5);
        set ("chat_output",({
           "掃地工說道：掃地是一種藝術，唯有真正的高手才能掃得清潔溜溜。\n"
        }));
        set("moving",1);
        set("speed",25);
        set("patrol",({"south","south","north","north"}));
        set("tactic_func","special_attack");
        wield_weapon( OWEAPON"broom" );
        equip_armor( OARMOR"glove2" );
}

int special_attack()
{
  object *victim;
  int i;

  if (!(victim=query_attackers())) return 0;

  if (random(10)<2) return 0;

  i=sizeof(victim);
  
  if (random(10)<7) {
    tell_room(environment(this_object()),
     "\n掃地工使出掃地劍法第一式，雙手握住掃把一端，急速揮動，幻成一圈黃光，向所有的敵人削去。\n\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+10);  
    return 1;
  }

  if (random(10)<7) {
    tell_room(environment(this_object()),
      "\n掃地工使出掃地劍法第二式，左手捏一劍訣，右手持掃把一端，一劍刺出，如石破天驚、風雨大至之勢，劍氣縱橫全場。\n\n"
    ,this_object());
    while(i--)
      victim[i]->receive_damage(random(10)+15);
    return 1;
  }

  tell_room(environment(this_object()),
   "\n掃地工使出掃地劍法第三式，右手持掃把緩緩揮出，突然身形一變，手中掃把如靈蛇般的刺向每個敵人的咽喉。\n\n"
  ,this_object());
  while(i--)
    victim[i]->receive_damage(random(10)+20);
  return 1; 
}
