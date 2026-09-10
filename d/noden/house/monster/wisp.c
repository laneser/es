#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "wisp", "鬼火" );
   set_short( "鬼火" );
	set_long(
		"你看到一團發光的鬼火，雖然很多人不相信鬼火的存在，但是你面前的\n"
		"這個東西毫無疑問地是活的！\n"
	);
   set( "race", "undead" );
	set( "unit", "團" );
	set( "alignment", -200 );
	set( "natural_defense_bonus", 10 );
	set( "natural_weapon_class1", 4 );
	set( "natural_max_damage1", 4 );
	set( "unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set_skill( "dodge", 35 );
	set_c_verbs( ({"%s發出一道小小的火花射向%s", "%s的影子晃了一晃，向%s衝去" }) );
	set_c_limbs( ({ "核心" }) );
}
