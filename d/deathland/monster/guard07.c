#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(15);
	set_name( "holy place guard", "聖地守衛" );
	add("id",({"guard"}));
	set_short( "a holy place guard", "聖地守衛" );
	set_long(
		"a holy guard.\n"
		"一個守護著矮人聖地的守衛者,他很盡忠於他的任務.\n"
	);
	set( "gender", "male" );
	set( "alignment", 700 );
	set_perm_stat( "dex", 22 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "kar", 18 );
	set("max_hp",500);
	set("hit_points",500);
	set_skill( "dodge", 90 );
	set_skill( "parry", 90 );
	set_natural_armor(50,25);
 	set_natural_weapon(10,5,15);
    set( "special_defense", (  ["all":20, "none": 20]  ) );
    set ("aim_difficulty",([ "critical": 30 ,"vascular": 20, "weakest": 20 ]) );
    equip_armor(Armour"/chainmail01");
    equip_armor(Armour"/boots01");
    set_skill("longblade",100);
    wield_weapon(Weapon"/sword01");
}

