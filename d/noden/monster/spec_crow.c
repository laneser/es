// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("spectral crow", "鬼魅烏鴉");
	add( "id", ({ "crow" }) );
   set_short("鬼魅烏鴉");
	set_long(
		"你看到一隻輪廓十分模糊的黑色烏鴉，一種不祥的預感告訴你這是種\n"
		"邪惡的化身。\n"
	);
	set( "unit", "只" );
	set( "alignment", -300 );
   set( "exp_reward", 320 );
   set( "max_hp", 220 );
   set( "hit_points", 220 );
   set_natural_armor( 15, 5 );
	set_natural_weapon( 7, 3, 8 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 5 );
	set( "aggressive", 1 );
	set( "tactic_func", "cry" );
	set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
	set_c_verbs( ({ "%s用嘴向%s用力一啄", "%s用爪子往%s抓去" }) );
}

int cry()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
  tell_room( environment(this_object()),
            "鬼魅烏鴉發出一陣淒厲的叫聲，好像瀕死生物的慘叫聲 ....\n",
		this_object() );
	CONFUSED->apply_effect( victim, 10, 5 );
	return 1;
}
