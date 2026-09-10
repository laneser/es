#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "fire guard", "火之護衛" );
        add ("id", ({ "fire", "guard" }) );
        set_short( "火之護衛");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"一位火之護衛，是大國師用道家正統心法所招喚出來的，他負有守衛此地的神聖
使命。\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 40, 15, 38 );
        set_natural_armor( 75, 13 );
        set ("gender", "male");
        set ("race", "daemon");
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":30,"none":30,"fire":50]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        equip_armor(ARMORS"/fire_leggings");
        equip_armor(ARMORS"/fire_amulet");
}

int fire_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"火之護衛突然將雙手按在護符上，變成了一團火焰向你撞來 !!\n",
       this_object() );
  dam = 45 + random(25);
  victim->receive_special_damage("fire",dam);
  return 1;
}
