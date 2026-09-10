#include "../moyada.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("killer ant", "殺人蟻");
	add( "id", ({ "ant"}) );
   set_short("殺人蟻");
	set_long(
		"一隻很兇惡的巨蟻，最好在它看上你之前趕快溜吧。\n"
	);
   set( "race", "insect" );
	set( "unit", "只" );
   set( "exp_reward", 247 );
	set( "alignment", -120 );
   set( "max_hp", 150 );
   set( "hit_points", 150 );
	set( "tactic_func", "big_bite" );
	set( "killer", 1 );
	set( "moving", 1 );
	set( "speed", 30 );
	set( "weight" ,100);
	set_natural_weapon( 13, 4, 7 );
	set_natural_armor( 16, 4 );
	set_perm_stat("str", 6);
	set_perm_stat("dex", 8);
	set( "c_death_msg", "%s尖叫一聲，抖了幾下不動了 ....\n" );
	set_c_limbs( ({ "頭部", "身體", "腳" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	setenv( "C_MIN", "一隻$N爬了過來。" );
	setenv( "C_MOUT", "$N往$D邊爬走了。" );
	set("alt_corpse", MOYADA"obj/ant_corpse1" );
}

int big_bite()
{
	object victim;

	if( random(20)>3 || !(victim = query_attacker()) ) return 0;
    tell_object(  victim,
        "殺人蟻爬到你的腳上，狠狠的一口咬下，你感到一陣劇痛！\n" );
    tell_room( environment(this_object()), 
"殺人蟻爬到"+victim->query("c_name")+"的腳上，狠狠的一口咬下！\n",
		({ this_object(), victim }) );
	SIMPLE_POISON->apply_effect( victim, 4, 5 );
	return 1;
}
