#include "../almuhara.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "evil boy", "小惡童" );
        add ("id", ({ "evil", "boy" }) );
        set_short( "小惡童");
        set("unit","位");
        set("alignment",-2000);
        set("wealth/gold",200);
        set_long("",
"一位可愛的小童子，他是大國師的隨侍二童之一。據說他是大國師在一場大戰中所收
服的，因為感激大國師饒而不殺之恩，於是便待在大國師的身旁，化身為一童子來服
侍大國師。\n"
        );
        set_perm_stat("int", 19);
        set_perm_stat("dex", 22);
        set_perm_stat("kar", 17);
        set_perm_stat("str", 25);
        set( "max_hp",500 );
        set( "hit_points", 500);
        set_natural_weapon( 40, 15, 35 );
        set_natural_armor( 80, 25 );
        set("skills",(["dodge":85,"block":85,"dagger":85]) );
        set("gender", "male");
        set("race", "daemon");
        set("tactic_func","evil_tactic");
        set("special_defense",(["all":40,"none":40]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(WEAPONS"/evil_dagger");
        equip_armor(ARMORS"/black_du_do");
}

int evil_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"惡童子口中唸唸有詞，突然他的雙眼爆射出紅光，向你襲來!!\n",
       this_object() );
  dam = 45 + random(25);
  victim->receive_special_damage("evil",dam);
  return 1;
}
