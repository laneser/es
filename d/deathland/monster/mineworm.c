
#include "../echobomber.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name("mine huge worm", "礦坑巨蟲");
	add("id",({"worm"}));
	set_short("A mine huge worm", "礦坑巨蟲");
	set_long(
		"You see a very very huge worm,which is searching food\n"
		"poisonus.\n",
	    "這是一條十分巨大的怪蟲,似乎可以一口把你給吞下.\n"
	);
	set( "unit", "條" );
	set( "alignment", -400 );
	set("aggressive",1);
	set_natural_weapon(7,3,4);
	set( "tactic_func", "emit_poison" );
	set_c_limbs( ({ "頭部", "身體" }) );
	set_c_verbs( ({ "%s張開它的大口，用它的牙齒向%s咬去" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"巨蟲的嘴巴噴出一股紫色的濃稠液體，剛好噴在你的面前 ....\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 12, 4 );
	return 1;
}
