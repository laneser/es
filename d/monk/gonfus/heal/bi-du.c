#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "simple_poison"

inherit DAEMON;

int query_fp_cost() { return 25; }

varargs int eungon(object me, int level)
{
	int chinese_mode, skill, fp;

	chinese_mode = can_read_chinese(me);

	if( me->query_temp("monk_poison") ) {
		tell_object( me, 
			"你剛逼過毒，沒力再做一次。\n" );
		return 0;
	}

	if( !me->query("conditions/"+COND_NAME) ) {
		tell_object( me, 
			"你並沒有中毒的情形。\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me,
			"在戰鬥中運功逼毒? 想死嗎?\n");
		return 0;
	}

	if( !skill = (int)me->query_skill("force-stun") ) {
		tell_object( me,
			"你並沒有學過穴道學的技能。\n");
		return 0;
	}

	fp = (int)me->query("force_points");
	if( !fp || fp < query_fp_cost() ) {
		tell_object( me,
			"你的內力不夠，不能夠運功逼毒。\n");
		return 0;	
	}
	tell_object( me, 
		"你想清楚穴道運行和全身脈絡分佈，運起身上內力，企圖逼出所中之毒 ....\n");

	tell_room( environment(me), 
		me->query("c_name")+"運起神功\，企圖逼出身上的毒素。\n" , me );

	me->set_temp("block_command", 1);
	me->set_temp("block_defense", 1);
	me->add("force_points", -query_fp_cost());
	call_out("result", 10-skill/20, me);
	return 1;
}

void result(object me)
{
	mixed poison;
	int skill, chinese_mode;

	if( !me ) return;
	me->delete_temp("block_command");
	me->delete_temp("block_defense");
	chinese_mode = can_read_chinese(me);

	if( !poison = (mixed)me->query( "conditions/" + COND_NAME ) ) {
		tell_object( me,
			"你的毒剛剛解了。\n");
		return;
	}

	if ( sizeof(poison) != 3 ) {
		log_file("Monk_bidu","Error poison index find in "+me->query("name")+"\n");
		me->delete("conditions/"+ COND_NAME);
		tell_object( me, "你中的毒很奇特 !! 請通知巫師 !!\n");
		return;
	}
	skill = (int)me->query_skill("force-stun");
	if( skill/2 + random(skill/2) > 5 * poison[1] * poison[2] / poison[0] ) {
		tell_object( me,
			"你成功的將體內的毒逼出體外了!\n");
		SIMPLE_POISON->remove_effect(me);
	} else {
		tell_object( me,
			"你功力不夠，所學有限，只逼出了一部份的毒素....\n");
		// make the result random case.
		switch( random(3) ) {
			case 1 : poison[0] *= 2; break;
			case 2 : poison[1] -= poison[1]/2; break;
			case 3 : poison[2] -= poison[2]/2; break;
		}
		me->set("conditions/"+COND_NAME, poison);
	}

	tell_room( environment(me), 
		me->query("c_name")+"吸了一口氣, 站了起來。\n", me );
	me->set_temp("monk_poison", 1);
	call_out("depoison_again", 120-skill/2, me);
}

void depoison_again(object player)
{
	if( !player ) return;
	tell_object( player, 
		"你感到你的內力充沛, 又能逼毒了。\n");
	player->delete_temp("monk_poison");
}
