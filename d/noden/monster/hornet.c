// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("hornet", "黃蜂");
   set_short("黃蜂");
	set_long(
		"你看到一隻嗡嗡叫的黃蜂，最好在你被它盯上之前趕快溜吧。\n"
	);
   set( "race", "insect" );
	set( "unit", "只" );
   set( "exp_reward", 156 );
	set( "tactic_func", "sting" );
	set( "killer", 1 );
	set( "pursuing", 1 );
	set( "moving", 1 );
	set( "speed", 15 );
	set( "natural_weapon_class1", 5 );
	set( "c_death_msg", "%s無力地落到地上，死翹翹了 ....\n" );
	set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
	set_c_verbs( ({ "%s發出嗡嗡的叫聲，往%s叮去" }) );
	setenv( "C_MIN", "一隻$N飛了過來。" );
	setenv( "C_MOUT", "$N往$D邊飛走。" );
}

int sting()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    tell_object( victim,
            "黃蜂飛到你的臉上，你感到臉上一陣刺痛！\n" );
    tell_room( environment(this_object()),
            "黃蜂飛到" + victim->query("c_name") + "的臉上，用尾針往下一螫！\n",
                ({this_object(),victim}) );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 3 );
	return 1;
}
