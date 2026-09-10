#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
    object item;
    
	::create();
	set_level(14);
	set_name( "strange jungle plant", "奇怪的叢林植物" );
	add("id",({"plant"}));
	set_short( "a strange green jungle plant", "奇怪的叢林植物" );
	set_long(
		"a strange green jungle plant.\n",
		"一種奇怪的綠色叢林植物,見到會動的就會主動攻擊.\n"
	);
	set( "alignment", 0 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "kar", 16 );
	set_skill( "dodge", 95 );
	set_natural_armor(70,15);
 	set_natural_weapon(33,20,25);
    set( "special_defense", (  [ "all":25, "none": 25, "fire":-25 ]  ) );
    set ("aim_difficulty",([ "critical":40 ]) );
    set ("unbleeding",1);
    set ("killer",1);
    set_c_verbs( ({ "%s伸出枝條快速擊向%s"}) );
    set_c_limbs( ({ "枝條", "枝幹" }) );
    set( "tactic_func", "my_tactic");
    
}

int my_tactic()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim, "這植物把你纏住並吸收你的精力.\n" );
      tell_room(environment(this_object()),
          "這植物把"+victim->query("c_name")+"纏住並吸收他的精力.\n"
          ,({victim,this_object(),}) );
      victim->receive_damage( 15 + random(20) );
      report(this_object(),victim);
      return 1;
      }
}
