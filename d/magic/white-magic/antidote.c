// This is a spell object
// By Annihilator@Eastern.Stories
#include <stats.h>
#include <conditions.h>

int query_sp_cost(object caster, int level, string target) { return 10 + level * 10; }

int query_need_skill(int level) { return 15+5*level; }

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object me, dest;

    me = this_player();
	chinese_mode = can_read_chinese(me);
	
	if( (int)me->query_skill("white-magic") < query_need_skill(level) ) {
		tell_object( me,"你的白魔法技能不足以使用這等級的魔法!\n");
		return 0;
	}
	
	if( target == "NONE" ) dest = me;
	else if( !(dest= present( target, environment(me) )) ) {
	    tell_object( me,"要對誰施展解毒術？\n");
	    return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	write("你開始吟誦白魔法中解毒術的咒文....。\n");
	tell_room( environment(me),
		me->query("c_name") + "開始以一種柔和的聲音吟誦咒文....。\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	mixed *cond;
	int power;

	caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster,"你發現你的目標已經離開這裡了。\n");
	  return;
	}
	if( !(cond = (mixed *)dest->query("conditions/simple_poison")) ) {
		tell_object( dest,"一團柔和的白色光芒籠罩著你，但是什麼也沒有發生。\n");
		return;
	}
	if( caster == dest )
		power = level * 20 + (int)caster->query_stat("int");
	else
		power = level * 15 + (int)caster->query_stat("int");
	if( power - cond[1]*cond[2] > random(cond[1]*cond[2]) ) {
		tell_object( dest,"一團柔和的白色光芒籠罩著你，你所中的毒解除了！\n");
		caster->gain_experience(cond[1]*cond[2]);
		call_other( CONDITION_PREFIX+"simple_poison", "remove_effect", dest );
	} else {
		tell_object( dest,"一團柔和的白色光芒籠罩著你，你所中的毒減輕了！\n");
		cond[1]--;
		cond[2]--;
		dest->set("conditions/simple_poison", cond);
	}
	tell_room( environment(dest),
		"一團柔和的白色光芒籠罩著"+dest->query("c_name")+"，然後逐漸散去。\n",
		dest );
}
