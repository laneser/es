// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

#define EFFECT_ID "windex"
#define BASIC_NEEDED 2
int query_sp_cost(int eff_lv,int skill_lv)
{
       return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_level() { return BASIC_NEEDED ; }


int acu_effect(int level, object target)
{
	int delay_time;
	string targetname ;
	object me ;

        me = this_player();
	
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	

        if(target == me) targetname = "自己" ;
        else
        { 
          targetname = target->query("c_name") ;
          tell_object(target,sprintf(
                     "%s隨地坐下並牽起你的手,緩緩將氣送進來。\n",
                     me->query("c_name")
                     ) ) ;
         }

	write(sprintf("你席地坐下並牽起%s的手,緩緩將氣送出去。\n",
	               targetname));

	tell_room( environment(me),sprintf( 
		"%s隨地坐下並牽起%s的手,緩緩將氣送出去。\n",
		 me->query("c_name"),targetname ) ,
		({ me ,target }) );

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int speed, duration ,verify, cur_val;

        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster, 
	    "不知怎麼的,也許是覺得你是個蒙古大夫。總之,你的患者走掉了。\n" 
	  );
	  return;
	}
	
	if( dest->query_temp("acup_effect/"+EFFECT_ID) ) {
		tell_object( dest,
			"你覺得體內的血氣開始快速流動，但是好像並沒有什麼不同....。\n"
		);
	} else {
		tell_object( dest,
			"你覺得體內的血氣開始沸騰，而周遭的人們好像都在慢動作的狀態中！\n"
		);
		speed = level - BASIC_NEEDED + 1 ;
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 4;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 4;
	
	        cur_val = (int)dest->query_stat("dex") ;
	        
	        if( (cur_val+speed) > 30 ) speed = 30 - cur_val ; 
	        
		dest->modify_stat("dex", speed);
		dest->set_temp("acup_effect/"+EFFECT_ID, 1);
		tell_room( environment(dest),sprintf( 
	        	"你嚇然發現%s的動作快得誇張, \n"
		        "到處都是他移動後留下的殘像。\n"
		        ,dest->query("c_name")), dest );
		call_out( "expire", duration, dest, speed );
	}
	return ;
}

void expire( object player, int speed)
{
    if( !player ) return;
    tell_object( player,
		"你覺得你的速度慢了下來，同時氣血的流動變得緩和....。\n" );
    player->modify_stat("dex", -speed);
    player->delete_temp("acup_effect/"+EFFECT_ID);
    return ;	
}


