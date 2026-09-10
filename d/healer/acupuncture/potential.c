// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories 
// acupuncture by Indra@ES
////#pragma save_binary
// #include "/std/object/prop.c"

//#include <priv.h>
#include <mudlib.h>
//#include <uid.h>

#define EFFECT_ID "potential"
#define BASIC_NEEDED 4

// int geteuid(seteuid(ROOT_UID)) ;
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
	me->block_attack(delay_time) ;
	me->set_temp("cast_busy", 1) ;
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
       
        if(target == me) targetname = "自己" ;
        else
        { 
          targetname = target->query("c_name") ;
          tell_object(target,sprintf(
                     "%s隨地坐下並牽起你的手,緩緩將氣送進來。\n",
                     me->query("c_name") ) ) ;
         }

	write(sprintf("你席地坐下並牽起%s的手,緩緩將氣送出去。\n",
	               targetname));

	tell_room( environment(me),sprintf( 
		"%s隨地坐下並牽起%s的手,緩緩將氣送出去。\n",
		 me->query("c_name"),targetname ),
		({ me ,target }) );
		
	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int normal_skill,duration ,eff ,i ,skill_no, mod ;
        string *skill_name ;
        mapping skills ;
        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	     tell_object( caster, 
	      "不知怎麼的,也許是覺得你是個蒙古大夫。總之,你的患者走掉了。\n" 
	         );
	     return;
    	    }
	
	if( dest->query_temp("acup_effect/"+EFFECT_ID) ) 
	    {
		tell_object( dest,
			"你覺得體內的血氣開始快速流動，但是好像並沒有什麼不同....。\n"
		);
	    }
	 else
	    {
		tell_object( dest,
			"你覺得體內的血氣開始快速流動，同時各種感應突然莫名的敏銳起來！\n"
		);
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 5;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 5;

                skills = dest->query_skills() ;

		skill_name = keys(skills) ;                
                skill_no = sizeof(skill_name) ;
		eff = (level-BASIC_NEEDED+1) ;
                if(!(skill_no)||skill_no==0) {
                     write("對方什麼都沒學過。\n") ;
                     return ;
				}
                for(i=0;i<skill_no;i++)
                   {
                     normal_skill=dest->query_perm_skill(skill_name[i]) ;
                     mod = normal_skill*eff/10 ;
                     dest->modify_skill( skill_name[i] , mod ) ;  
// in here , skill store the increasement of skills
                     skills[skill_name[i]] = mod ;                           
                   }  
        	tell_room( environment(dest),sprintf(
		    "你突然覺得%s身上莫名的多出了一股逼人的英氣。\n",
		    dest->query("c_name") ),dest );

		dest->set_temp("acup_effect/"+EFFECT_ID, 1);
		call_out( "expire", duration, dest, skills);
	}
}

void expire(object player,mapping skill_mod)
{
    int i,skill_no,mod_val ;
    mixed skill_name ;
    mapping skills ;
    
    if( !player ) return;
    skills = player->query_skills() ;
    skill_name = keys(skills) ; 
    for(i=0 ; i <sizeof(skill_name);i++)
    {
   //    normal_skill= player->query_perm_skill(skill_name[i]) ;
   //    current_skill= player->query_skill(skill_name[i]) ;         
   //    player->modify_skill(skill_name[i],  normal_skill - current_skill ); 

         mod_val = skill_mod[skill_name[i]] ;

         if(!(mod_val))
         	continue;
/*
   //   不正常的理由是剛剛有加強的技能現在卻找不到了..     
              tell_object(player,"你的技能檔案似乎不正常,請速洽巫師解決。\n") ;
// 這部份不正確，因為如果 player skill 太低，可能 modify = 0;
By Ruby@ES 96'1/27
*/
         else
              player->modify_skill(skill_name[i],  -mod_val );
    }
    player->delete_temp("acup_effect/"+EFFECT_ID);

    tell_object( player,
		"你莫名地被激發出來的潛能,又莫名的回到往日沉眠的狀態....。\n" );
    
    return ;	
}

