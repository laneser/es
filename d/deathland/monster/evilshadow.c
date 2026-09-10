#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "evil shadow", "邪惡幻影" );
	add("id",({"shadow","evilshadow"}));
	set_short( "邪惡幻影" );
	set_long(
		"一個令人懼怕的邪惡幻影\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 19 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 12 );
	set_skill( "dodge", 88 );
	set( "tactic_func", "my_tactic" );
	set_natural_armor( 73 , 24);
	set_natural_weapon(38,12,24);

    set("aggressive",1);
    set("pursuing",1);
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪惡幻影發出可怕的笑聲,並且手中形成一團黑色的光球,向你飛去.\n"
          );
      tell_room(environment(this_object()),
          "邪惡幻影發出可怕的笑聲,並且手中形成一團黑色的光球,向"+victim->query("c_name")+"飛去.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",20+random(20));
      report(this_object(),victim);
      return 1;
      }
}
