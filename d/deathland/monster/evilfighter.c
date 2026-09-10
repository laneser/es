#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "evil fighter", "邪惡戰士" );
	add("id",({"fighter","evilfighter"}));
	set_short( "邪惡戰士" );
	set_long(
		"一個令人懼怕的邪惡戰士,有著令人無法想像的魔力\n"
	);
	set( "alignment", -1200 );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 23 );
	set_perm_stat( "kar", 19 );
	set_skill( "dodge", 98 );
	set_skill( "parry", 90 );
	set_skill( "longblade",100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "vascular" );
	set( "tactic_func", "my_tactic" );
	set_natural_armor(63,24);
	set_natural_weapon(38,12,24);
    set( "special_defense",( ["all":25] ) );
    set("aggressive",1);
    equip_armor(Armour"/plate06");
    wield_weapon(Weapon"/sword03");
}

int my_tactic()
{
	object victim;

	if( random(20)>3 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪惡幻影發出可怕的哭聲,並且手中形成一團綠色的光球,向你飛去.\n"
          );
      tell_room(environment(this_object()),
          "邪惡幻影發出可怕的笑聲,並且手中形成一團綠色的光球,向"+victim->query("c_name")+"飛去.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",30+random(10));
      report(this_object(),victim);
      return 1;
      }
}
