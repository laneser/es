// This is a spell object
// By Annihilator@Eastern.Stories

int query_sp_cost(object caster, int level, string target) { return 30 + level * 30; }

int query_need_skill(int level) { return 35+10*level; }

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
	    tell_object( me,"要對誰使用力量增強法術？\n");
        return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	
 	write("你開始吟誦白魔法中力量增強法術的咒文....。\n");
	tell_room( environment(me),
	     me->query("c_name") + "開始以一種堅定的聲音吟誦咒文....。\n",me );
	
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration;

    caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster,"你的目標走掉了。\n" );
	  return;
	}
	
	if( dest->query_temp("effect/power-boost") ) {
		tell_object( dest,
		  "一團耀眼的紅色光芒籠罩著你，但是你覺得並沒有什麼不同....。\n"
		);
	} else {
		tell_object( dest,
			"一團耀眼的紅色光芒籠罩著你，你覺得全身開始充滿了力量！\n"
		);
		boost = level+1;
		if( caster == dest )
			duration = (level+1) * 50 + (int)caster->query_stat("pie") * 3;
		else
			duration = (level+1) * 35 + (int)caster->query_stat("pie") * 3;
		dest->modify_stat("str", boost);
		dest->set_temp("effect/power-boost", 1);
		call_out( "expire", duration, dest, boost );
	}
	tell_room( environment(dest), 
		"一團耀眼的紅色光芒籠罩著"+dest->query("c_name")+"，然後逐漸散去。\n",
		dest );
}

void expire( object player, int boost )
{
    if( !player ) return;
	tell_object( player,"你覺得全身肌肉放鬆了下來，不再充滿了魔法般的力量....。\n");
	player->modify_stat("str", -boost);
	player->set_temp("effect/power-boost", 0 );
}
