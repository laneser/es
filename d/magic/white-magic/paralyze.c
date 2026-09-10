// This is a spell object
// By Annihilator@Eastern.Stories

int query_sp_cost(object caster, int level, string target) { return 20 + level * 10; }

int query_need_skill(int level) { return 15+10*level; }

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
	
	if( target == "NONE" ) dest = me->query_attacker();
	else dest = present( target, environment(me) );
	if( !dest || dest==this_player() || dest->query("no_attack")
	|| dest->stop_attack() ) {
	  tell_object( me,"要對誰使用麻痺術？\n");
	  return 0;
	}
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3+level;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	write("你開始吟誦白魔法中麻痺術的咒文....。\n");
	tell_room( environment(me),
		me->query("c_name") + "開始以一種遲緩的聲音吟誦咒文....。\n",
		me );
		
	dest->kill_ob(me);
	me->kill_ob(dest);
	call_out( "effect", delay_time, level, me, dest );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int boost, duration;
    object env;
    
    caster->set_temp("cast_busy", 0);
    if( !dest ) {
      tell_object( caster,"你發現你的目標已經死了。\n");
      return;
    }
    env = environment(caster);
    if( !env || !present( dest, env ) ) {
      tell_object( caster,"你發現你的目標已經不在這裡了。\n");
      return;
    }
	if( dest->query_temp("effect/paralyze") ) {
		tell_object( dest,
		    "一團耀眼的粉紅色光芒籠罩著你，但是你覺得並沒有什麼不同....。\n");
	} else {
		tell_object( dest,
			"一團耀眼的粉紅色光芒籠罩著你，你覺得全身肌肉開始變得僵硬 ....。\n"
		);
		boost = (int)dest->query_stat("dex") / 2;
		duration = (level+1) * 15 + (int)caster->query_stat("pie") * 3;
		dest->modify_stat("dex", -boost );
		dest->set_temp("effect/paralyze", 1);
		call_out( "expire", duration, dest, boost );
	}
	tell_room( environment(dest),
		"一團耀眼的粉紅色光芒籠罩著"+dest->query("c_name")+"，然後逐漸散去。\n",
		dest );
}


void expire( object player, int boost )
{
    if( !player ) return;
	tell_object( player,"你覺得全身肌肉又重新回到你的意志控制之下 ....。\n");
	player->modify_stat("dex", boost);
	player->set_temp("effect/paralyze", 0 );
}
