#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "thunder guard", "雷之護衛" );
        add ("id", ({ "thunder", "guard" }) );
        set_short( "雷之護衛");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"一位雷之護衛，是大國師用道家正統心法所招喚出來的，他負有守衛此地的神聖
使命。\n"
        );
        set_perm_stat("int", 25);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 23);
        set_perm_stat("con",30);
        set_perm_stat("kar",25);
        set_natural_weapon( 55, 25, 45 );
        set_natural_armor( 70, 8 );
        set("skills",(["parry":80]) );
        set("gender", "male");
        set("race", "daemon");
        set("tactic_func","thunder_tactic");
        set("special_defense",(["electricl":40,"all":20]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        equip_armor(ARMORS"/thunder_gloves");
        equip_armor(ARMORS"/thunder_amulet");
}

int thunder_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"雷之護衛突然高舉他的護符，兩三條電光自護符中發出向你射來 !!\n",
       this_object() );
  dam = 50 + random(30);
  victim->receive_special_damage("electric",dam);
  return 1;
}

