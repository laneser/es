// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

int query_sp_cost(int eff_lv,int skill_lv)
{
    return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_skill() { return 0 ; }


int acu_effect(int level, object target)
{
	int delay_time;
	object me ;

        me = this_player();
	
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
	
	write(  "你隨地坐下並牽起"+target->query("c_name")+
		"的手,緩緩將氣送出去。\n" );
	tell_room( environment(me), 
		me->query("c_name") + "隨地坐下並牽起"
		+target->query("c_name")+"的手,緩緩將氣送出去。\n",
		({ me ,target}) );
        tell_object(target,me->query("c_name") + 
                           "隨地坐下並牽起你的手,緩緩將氣送進來。\n" ) ;

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	if( !dest || !present(dest, environment(caster)) ) 
	{
	  tell_object( caster, 
	    "不知怎麼的,也許是覺得你是個蒙古大夫。總之,你的患者走掉了。\n");
	  return;
	}
	
	tell_object( dest,
	    "你覺得體內的血氣開始快速流動，但是你全身突然開始劇痛....。\n");
	tell_room( environment(dest), 
	        dest->query("c_name")+"的臉開始發紅, 紅得像是要滲出血來了。\n"
		,dest );
	tell_object( caster,
	    "你突然發現對方血氣向你激湯過來,當你想收手已經來不及....。\n");
	dest->receive_damage( level * 5 );        
	caster->receive_damage( level * 5 );        
        return ;
}



