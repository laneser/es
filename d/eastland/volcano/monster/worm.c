#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("carrion creeper", "食□蟲");
	add( "id", ({ "creeper" }) );
	set_short( "食□蟲");
	set_long(
	  "你看到一隻食□蟲，正蠕蠕而動，它專門吃腐爛的□體，是大自然的清道夫。\n"
	);
	set( "unit", "只" );
	set( "alignment", 50 );
	set( "tactic_func", "wormattack" );
        set_natural_weapon(2,4,5);
	set_c_limbs( ({ "頭部", "身體" }) );
	set_c_verbs( ({ "%s張開大口向%s咬去" }) );
}

int sting()
{
	object victim;

	if( random(20)>7 || !(victim= query_attacker()) ) return 0;
	tell_object( victim, 
		"食□蟲的嘴裡吐出一股惡臭，你聞了差一點沒有暈過去！\n");
	tell_room( environment(this_object()),
		"食□蟲往"+victim->query("c_cap_name")+"吐出一股惡臭\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 5 );
	return 1;
}
