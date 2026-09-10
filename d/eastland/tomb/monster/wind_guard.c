#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "wind guard", "風之護衛" );
        add ("id", ({ "wind", "guard" }) );
        set_short( "風之護衛");
        set("unit","位");
        set("alignment",500);
        set("wealth/gold",100);
        set_long(
"一位風之護衛，是大國師用道家正統心法所招喚出來的，她負有守衛此地的神聖
使命\。\n"
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_perm_stat("kar",20);
        set_natural_weapon( 46, 14, 36 );
        set_natural_armor( 77, 14 );
        set("skills",(["dodge":80]) );
        set("gender", "female");
        set("race", "daemon");
        set("tactic_func","wind_tactic");
        set("special_defense",(["all":40,"none":40]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        equip_armor(ARMORS"/wind_boots");
        equip_armor(ARMORS"/wind_amulet");
}

int wind_tactic()
{
  object ob1,ob2;
  int times,heal;
  
  ob1=this_object();
  
  if ( !(ob2=query_attacker()) || (random(10)>2)) return 0;
  
  tell_room(environment(),
       "\n"+"風之護衛將雙手舉起，突然一陣清風包圍了她 !!\n",
       this_object() );
  heal = 45 + random(25);
  ob1->receive_healing(heal);
  return 1;
}
