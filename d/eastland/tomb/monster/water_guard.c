#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "water guard", "水之護衛" );
        add ("id", ({ "water", "guard" }) );
        set_short( "水之護衛");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"一位水之護衛，是大國師用道家正統心法所招喚出來的，他負有守衛此地的神聖
使命。\n"
        );
        set_perm_stat("int", 25);
        set_perm_stat("str", 23);
        set_perm_stat("dex", 20);
        set_perm_stat("con",30);
        set_perm_stat("kar",30);
        set_natural_weapon( 42, 12, 39 );
        set_natural_armor( 78, 11 );
        set ("gender", "male");
        set ("race", "daemon");
        set("tactic_func","water_tactic");
        set("special_defense",(["cold":30,"none":30,"fire":-20]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        equip_armor(ARMORS"/water_ring");
        equip_armor(ARMORS"/water_amulet");
}

int water_tactic()
{
  object victim;
  int dam;
  
 if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"水之護衛拿起他的護符向你揮了揮，你突然覺得一陣寒意!!\n",
       this_object() );
  dam = 50 + random(25);
  victim->receive_special_damage("cold",dam);
  return 1;
}
