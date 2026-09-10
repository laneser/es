#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Guan Sheng","關勝");
    add("id",({"guan","sheng"}) );
    set_short("關勝");
	set_long(@C_LONG
外號大刀關勝，幼讀兵書，深通武藝，使一口青龍偃月刀，有萬夫不當
之勇。本充蒲東巡簡．生的臥蠶眉，丹鳳眼，面如重棗，現為梁山泊馬
軍五虎將中第一大將。
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",25);
    set_perm_stat( "int",17);
    set_perm_stat( "karma",27);
    set_skill("longblade",100);
    set_skill("parry",100);	
    set ("max_hp",1000);
    set ("hit_points",1000);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
    set ("weight", 40);
    set ("tactic_func","hack");
    equip_armor(TARMOR"green_hood");
    wield_weapon(TWEAPON"dragonblade");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"green_chainmail");
    equip_armor(TARMOR"golden_boots");
    equip_armor(TARMOR"golden_cloak");
}
int hack()
{
  object victim;
  string name,c_name;
  if (!(victim=query_attacker())) return 0;
  name =victim->query("name");
  c_name =victim->query("c_name");
  if (random(10)<2) { 
  tell_room(environment(this_object()),
  "\n關勝用臺語喝道: 天罡破....破....破....\n"
  "關勝的青龍偃月刀自半空劃出一道刀光，造成敵人不可思議的傷害\n\n"
);
  victim->receive_special_damage("none",50);
return 1;
}
return 0;
}

