#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "skeleton black knight", "駭骨族黑武士" );
	add("id",({"skeleton","knight",}));
	set_short( " a skeleton black knight", "駭骨族黑武士" );
	set_long(
		"a terrible skeleton knight.\n"
		"一個令人懼怕的駭骨族黑武士,殘忍嗜殺,冷酷無情,\n"
		"最可怕的是一擊必殺的可怕必殺技.\n"
	);
	set( "gender", "male" );
	set( "alignment", -2000 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", 100 );
	set_skill( "parry", 100 );
	set_skill( "longblade",100 );
	set_natural_armor(110,0);
 	set_natural_weapon(45,25,55);
    set( "special_defense", (  ["all":60, "none": 55,"divide":-40,"fire":-30]  ) );
    set ("aim_difficulty",([ "critical":33,"weakest":32 ]) );
    set("unbleeding",1);
    set("killer",1);
    set( "tactic_func", "my_tactic");	
    wield_weapon(Weapon"/sword05");
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "駭骨族黑武士看準你的弱點快.準.狠.地猛擊你.\n" );
      tell_room(environment(this_object()),
          "駭骨族黑武士快.準.狠.地猛擊"+victim->query("c_name")+".\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 75 + random(55) );
      report(this_object(),victim);
      return 1;
      }
}
