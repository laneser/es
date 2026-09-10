#include "../saulin_temple.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name("Mami mushroom", "靈芝媽媽");
	add("id",({"mami","mushroom"}));
	set_short("靈芝媽媽");
	set_long(
	    "一隻正因為小孩被欺負而生氣的靈芝媽媽，它正用憤怒的眼光瞪著你。\n"
	);
	set("unit", "只");
	set("alignment", 350 );
	set("killer",1);
	set("max_hp", 500);
	set("hit_points", 500);
	set_perm_stat("dex",20);
	set_perm_stat("str",16);
	set_perm_stat("int",18);
	set_natural_weapon(20, 12, 23);
	set_natural_armor(60, 24);
	set( "special_defense", ([ "all" : 40, "none" : 20 ]) );
	set( "aim_difficulty", ([ "ganglion" : 65, ]) );
	set( "unbleeding", 1);
	set( "tactic_func", "sleepy" );
	set( "alt_corpse", SAULIN_OBJ"big_pill" );
	set_c_verbs(({ "%s用頭撞%s", "%s用身體撞%s" }));
	set_c_limbs(({ "身體", "頭部" }));
	set("c_death_msg","%s突然毫無生氣地躺在地上... 不動了。\n");
}

int sleepy()
{
	object victim;

	if( random(20)>6 || !(victim = query_attacker()) ) return 0;
    if( victim->query("stop_attack") ) return 0;
    tell_object( victim, 
      "靈芝媽媽散發出一種香氣，你感到昏昏欲睡!!\n");

    tell_room( environment(this_object()), 
      "靈芝媽媽，散發出一種奇特的氣息把"+victim->query("c_name")+"迷的不醒人事!!\n",
      ({ victim, this_object() })
    );
    victim->block_attack(6);
    victim->set_temp("msg_stop_attack", 
       "( 你現在全身無力，只想好好的睡一覺! )\n"
    );
    return 1;
}
