#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "evil wight", "邪惡怨靈" );
	add("id",({"wight"}));
	set_short( "evil shadow", "邪惡怨靈" );
	set_long(
		"a terrible evil wight.\n"
		"一個令人懼怕的邪惡怨靈,據說是那些不甘心死去的人的靈魂所形成的 .\n"
	);
	//set( "gender", "natural" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "int", 17 );
	set_perm_stat( "kar", 12 );
	set_skill( "dodge", 93 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 35, 16, 27 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("aggressive",1);
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪惡怨靈發出可怕的笑聲,並且以它如風的速度向你飛來吸取你的生命力.\n"
          );
      tell_room(environment(this_object()),
          "邪惡怨靈發出可怕的笑聲,並且以它如風的速度向"+victim->query("c_name")+"飛去.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",10+random(17));
      report(this_object(),victim);
      return 1;
      }
}
