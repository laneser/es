// /d/noden/monster/snake.c

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name("ghoul", "綠色食屍鬼");
   set_short( "綠色食屍鬼");
	set_long(
		"這個食屍鬼長得又醜又兇，皮膚黏呼呼的，聞起來還有一股臭味。\n"
	);
   set( "race", "undead" );
	set( "unit", "個" );
	set( "alignment", -600 );
   set( "exp_reward", 2530 );
   set( "max_hp", 350 );
   set( "hit_points", 350 );
	set( "natural_weapon_class1", 16 );
	set( "natural_min_damage1", 8 );
	set( "natural_max_damage1", 18 );
	set( "tactic_func", "emit_poison" );
	set( "wealth/gold", 25 );
	wield_weapon("/d/noden/item/bronze_claw");
	set_c_verbs( ({ "%s張開大嘴，往%s咬去", "%s用黏呼呼的手往%s一抓",
		"%s抬腿往%s踢去" }) );
}

int emit_poison()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
   if( random(20)<5) {
            tell_room( environment(this_object()),
                    "食屍鬼從嘴巴噴出一股綠色的臭氣，剛好噴在你的面前 ....\n",
			this_object() );
		(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 15, 6 );
	} else {
            tell_room( environment(this_object()),
                    "食屍鬼發出一陣「哇...拉...拉...」的怪叫！\n",
			this_object() );
            (CONDITION_PREFIX + "confused")->apply_effect( victim, 12, 5 );
	}
	return 1;
}
