#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    
	::create();
	set_level(15);
	set_name( "swamp plant", "沼澤植物" );
	add("id",({"plant"}));
	set_short( "swamp plant", "沼澤植物" );
	set_long(
		"a strange black swamp plant.\n",
		"一種生長在灰暗島沼澤的黑色植物,它會主動地攻擊任何生物.\n"
	);
	set( "alignment", 0 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 95 );
	set_natural_armor(85,15);
 	set_natural_weapon(40,25,35);
    set( "special_defense", (  [ "all":25, "none": 25, "fire":-10 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
    set( "tactic_func", "my_tactic");
    set_c_verbs( ({ "%s伸出枝條快速擊向%s"}) );
    set_c_limbs( ({ "枝條", "枝幹" }) );
    
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "這植物把你纏住並吸收你的精力.\n" );
      tell_room(environment(this_object()),
          "This plant drain the power of "+ victim->query("name")+".\n",
          "這植物把"+victim->query("c_name")+"纏住並吸收他的精力.\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 25 + random(30) );
      report(this_object(),victim);
      return 1;
      }
}
