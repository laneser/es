// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

int query_sp_cost(int eff_lv,int skill_lv)
{
                  return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_skill() { return 2 ; }


int cast(int level, object target)
{
	int delay_time;
	object me ;

        me = this_player();
	
//	if( me->query("npc") && me->query("magic_delay") )
//	    delay_time = (int)me->query("magic_delay");
//	else
	  
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
	
	write(  "你隨地坐下並牽起"+target->query("c_name")+
		"的手,緩緩將氣送出去。\n" );
	tell_room( environment(me), ({
		me->query("c_name") + "隨地坐下並牽起"
		+target->query("c_name")+"的手,緩緩將氣送出去。\n"}),
		me ,target);
        tell_object(target,me->query("c_name") + 
                           "隨地坐下並牽起你的手,緩緩將氣送進來。\n" ) ;

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int speed, duration;

        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster, 
	    "不知怎麼的,也許是覺得你是個蒙古大夫。總之,你的患者走掉了。\n" 
	  );
	  return;
	}
	
	if( dest->query_temp("effect/windex") ) {
		tell_object( dest,
			"你覺得體內的血氣開始快速流動，但是好像並沒有什麼不同....。\n"
		);
	} else {
		tell_object( dest,
			"你覺得體內的血氣開始沸騰，而周遭的人們好像都在慢動作的狀態中！\n"
		);
		speed = level ;
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 4;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 4;
		dest->modify_stat("dex", speed);
		dest->set_temp("effect/windex", 1);
		call_out( "expire", duration, dest, speed );
	}
	tell_room( environment(dest), ({
		"你嚇然發現"+dest->query("c_name")+"的動作快得誇張, \n"
		"到處都是他移動後留下的殘像。\n"}),
		dest );
}

void expire( object player, int speed)
{
    if( !player ) return;
	tell_object( player,
		"你覺得你的速度慢了下來，同時氣血的流動變得緩和....。\n" );
	player->modify_stat("dex", -speed);
	player->set_temp("effect/windex", 0 );
}


