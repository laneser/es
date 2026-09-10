#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object cloak;
        ::create();
        set_level(18);
        set_name( "draconian flamen budbadbump", "龍人祭司 巴德北特.龐博" );
        add ("id", ({ "draconian", "flamen","budbadbump" }) );
        set_short( " 龍人祭司 巴德北特.龐博");
        set("unit","位");
        set("alignment",600);
        set("weight",400);
        set("wealth/gold",100);
        set_long(@C_LONG
龍人祭司 巴德北特.龐博是一個博學多才的人，他對許多神秘的事件有獨特
的研究，例如巫術，針灸，內功\，以及古文明的祭典等都有其獨到的見解，
實是一個值的敬重的老先生。
C_LONG
        );
        set_perm_stat("int", 26);
        set_perm_stat("dex", 16);
        set_perm_stat("kar",20);
        set("max_hp",500);
        set("hit_points",500);
        set_natural_weapon(20, 10, 20);
        set_natural_armor(70, 30);
        set ("special_defense",(["all":40,"none":60]));
        set ("gender", "male");
        set_skill("shortblade",100);
        set_skill("dodge",100);
        set("tactic_func","sleet_tactic");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
      
        cloak=new(Lditem"scroll");
        cloak->move(this_object());
        
        wield_weapon(Lditem"shortsword");
        equip_armor(Lditem"cloak");
        equip_armor(Lditem"leggings");
}

int sleet_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(this_object()),
       "\n突然巴德北特.龐博喃喃的念出神秘的咒語，一陣冰雪風暴向你襲來。\n\n");
  dam=50 + random(30);
  magics->receive_special_damage("sleet",dam);
  return 1;
}
