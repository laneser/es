#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "bleeding"

inherit DAEMON;

int query_fp_cost() { return 25; }

int eungon(object me, int level)
{
	mixed bleed;
	int chinese_mode, skill, fp;
        
	chinese_mode=can_read_chinese(me);
	if( me->query_temp("monk_bleeding") ) {
		tell_object( me, 
			"你的傷口剛剛處理過了。\n");
		return 0;
	}
	
	if( me->query("weapon1") ) {
		tell_object(me, 
			"喂...拿武器是無法施展輪指封穴的。\n");
		return 0;
	}

	if( !bleed = me->query("conditions/"+COND_NAME) ) {
		tell_object( me, 
			"你並沒有失血的情形。\n");
		return 0;
	}

	if( !skill = (int)me->query_skill("force-stun") ) {
		tell_object( me,
			"你並沒有學過點穴的技能。\n");
		return 0;
	}

    fp = (int)me->query("force_points");
    if ( !fp || fp < query_fp_cost() ) {
        tell_object( me,
            "你的內力不夠，不能夠施展輪指封穴。\n");
        return 0;
    }

	me->set_temp("monk_bleeding", 1);
	me->add("force_points", -query_fp_cost());
	tell_object( me,
		"你右手疾點自己的商陽，大巨，太白等穴想替自己的傷口止血....\n");
	tell_room( environment(me), 
		me->query("c_name")+"右手疾點，替他的傷口止血。\n", me );
		
	if( skill/2 + random(skill/2) > 10 * bleed[1] * bleed[2] / bleed[0] )
		BLEEDING->remove_effect(me);
	else {
		tell_object( me, 
			"但是結果只是減緩了傷勢，並未完全成功。\n");
		// make the result random case.
		switch( random(3) ) {
			case 1 : bleed[0] *= 2; break;
			case 2 : bleed[1] -= bleed[1]/2; break;
			case 3 : bleed[2] -= bleed[2]/2; break;
		}
		me->set("conditions/"+COND_NAME, bleed);
	}
	call_out("debleeding_again", 100-skill/2, me);
	return 1;
}

void debleeding_again(object player)
{
	if( !player ) return;
	player->delete_temp("monk_bleeding");
}
