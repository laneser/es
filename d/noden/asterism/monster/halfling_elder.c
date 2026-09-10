#include "../asterism.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "halfling elder", "半身人長老" );
        add ("id", ({ "halfling", "elder" }) );
   set_short( "半身人長老" );
        set("unit","位");
        set("alignment",600);
        set("wealth/gold",100);
        set_long("",
            "這個怎麼看都像個老頑童似的半身人長老，正笑咪咪的望著你。\n"
        );
        set_perm_stat("int", 26);
        set_perm_stat("dex", 24);
        set_perm_stat("con",27);
        set_perm_stat("kar",26);
        set_natural_weapon( 40, 20, 33 );
        set_natural_armor( 60, 30 );
        set("aim_difficulty",(["critical":100,"weakest":20,
                               "vascular":35,"ganglion":35 ])) ;
        set ("gender", "male");
        set ("race", "halfling");
        set_skill("whip",100) ;
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":50,"none":60]));
        set_c_verbs(({"用%s揮向%s攻擊","用%s向%s敲擊"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(WEAPONS"long_whip");
        equip_armor(ARMORS"boots03");
        equip_armor(ARMORS"leggings02");
        equip_armor(ARMORS"cloak_h01");
        equip_armor(ARMORS"gloves02");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
       "半身人長老口中唸唸有詞....你眼前景物一晃,你被迎面而來的戰車撞倒。\n"
       "緊接著又被第二輛輾過,第三輛....你只能躺著無助地望著混戰中的一切....\n"
       "等你恢復知覺卻發現還站在原處,但身上依然感到被輾過的疼痛。\n",
       this_object() );
  dam = 35 + random(26);
  magics->receive_special_damage("mental",dam);
  return 1;
}
       

