#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "elf elder", "精靈長老" );
        add ("id", ({ "elf", "elder" }) );
        set_short( "精靈長老" );
        set("unit","位");
        set("alignment",600);
        set("wealth/gold",100);
        set_long(
           "精靈長老喬納斯是一位和藹可親的長者，由於他是當年魔族入侵時\n"
           "打倒魔王軍團長(yamato)的英雄，故而精靈族的每一份子都對其心懷\n"
           "尊敬。\n"
        );
        set_perm_stat("int", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 45, 10, 40 );
        set_natural_armor( 60, 40 );
        set ("gender", "male");
        set ("race", "elf");
        set("tactic_func","fire_tactic");
   set("special_defense",(["all":50,"fire":35,"poison":30,"none":35]));
        set_c_verbs(({"用%使出精靈杖法向%s攻擊","用%s向%s刺去","用%s向%s敲擊"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(LWEAPON"staff");
        equip_armor(LARMOR"boots");
        equip_armor(LARMOR"legging");
        equip_armor(LARMOR"cloak");
        equip_armor(LARMOR"armband");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
      "\n突然精靈長老念出一串神秘的咒語, 你看見一片火海向你襲來。\n\n",
       this_object() );
  dam = 65 + random(30);
  magics->receive_special_damage("fire",dam);
  return 1;
}
