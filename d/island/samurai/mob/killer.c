#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Killer Genan", "殺手 幻庵" );
	add( "id", ({ "killer","genan" }) );
	set_short( "Killer Genan", "殺手 幻庵" );
	set_long(@AAA
幻庵是一個外表可起來相當邪惡的男子，渾身散發出一股強烈的殺氣，他
是武士團所屬的特殊殺手，據說他曾經刺殺過遙照天皇，雖然沒有成功但
仍能全身而退，可見他的厲害了！！
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );    
        set( "max_hp",700 );
        set( "hit_points",700 );
 	set_natural_armor( 90,40 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":35,"none":35 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":30,"ganglion":50,
                                 "vascular":30 ]));
        set( "stun_difficulty/ma",10);  
	set( "alignment", -2500 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "dodge",100);
        set_skill("tactic",100);
        set("tactic","berserk");
        set( "wealth" , ([ "gold": 50 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );
        wield_weapon(MOBJ"lock");    
}
int att_gonfus()
{
     object victim;
     int dam1,dam2,n;
     
     if( !(victim = query_attacker()) || (random(20)>4) ) return 0;
     else {
     switch (n=random(2))
{ case 0:
    {
     tell_room(environment(this_object()), 
     "\n幻庵突然張口對"+victim->query("c_name")+"噴了一口毒氣\n\n"
     );
      dam1 = 15 + random(25);
      victim->receive_special_damage("poison", dam1 );
      report(this_object(),victim);
      return 1;
      }
  case 1:
     { 
       tell_room(environment(this_object()),
       "\n幻庵伸手抓住"+victim->query("c_name")+"並張口開始亂咬\n\n"
       );
       dam2 = 15 + random(15);
       victim->receive_special_damage("poison",dam2);
       report(this_object(),victim);
       return 1;
      }
}
}
}
