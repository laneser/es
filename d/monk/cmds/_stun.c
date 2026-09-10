// Fp cost = 5 - stun_skill/30 ( that is 5~2)   +    5 (if 點中!) 
////#pragma save_binary

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON;

#define stun_point ({ "青靈", "缺盆", "檀中", "築賓", "肩貞" })

int block_victim(object me, object victim); 
int stun_work(object me, object victim);

int cmd_stun()
{
	int skill, fp_cost, delay;
	object me, victim;
	
	me = this_player();
    if( me->query_temp("stun_busy") )
    	return notify_fail("\n *** 你還在等待機會點穴，不能分心。*** \n");
    if( me->query_temp("busy") )
    	return notify_fail("\n  你正在專心作別的事情，不能分心點穴。\n");
	victim = me->query_attacker();
	if( !victim ) return notify_fail("你沒在戰鬥中，找不到對手在哪裡!\n");
		
	if( !skill = (int)me->query_skill("force-stun") )
		return notify_fail( "你沒有練過點穴，不瞭解穴道位置，練個幾年再來吧 !!!\n");

	fp_cost = 5 - skill / 30;
	if( !fp_cost || (int)me->query("force_points") < (fp_cost + 5) )
		return notify_fail("\n *** 你的內力不足！*** \n");
	else
		me->add("force_points", -fp_cost );


	tell_object(me, set_color("\n *** 你全神貫注，開始要找機會施展你點穴的神技 ! ***\n", "HIC",me) );

	delay = 15 - skill/20 - random((int)me->query("force_effect"));
	if( delay < 1 ) delay = 1;
	me->set_temp("stun_busy",1);
	me->set_temp("busy",1);
	call_out("stun_work", delay, me, victim);
	return 1;
}

int stun_work(object me, object victim)
{
	int skill, chance;
	string loc;
	object weapon, *attackers;

	if ( !me ) return 1;
	me->delete_temp("stun_busy");
	me->delete_temp("busy");
	if ( ! me->query_attackers() || !victim) {
		tell_object(me,"你的戰鬥結束了，不需要點穴了! \n");
		return 1;
	}

	skill = (int)me->query_skill("force-stun");
	if( weapon = me->query("weapon1") )
		switch( weapon->query("type") ) {
			case "longblade" : 	skill *= 5;		break;
			case "bo"        :  skill *= 7;		break;
			case "shortblade":  skill *= 5;		break;
			case "dagger"    : 	skill *= 9;		break;
			case "blunt"     : 	skill *= 0;		break;
			case "axe"       : 	skill *= 0;		break;
			case "thrusting" : 	skill *= 6;		break;
			case "polearm"   : 	skill *= 0;		break;
			case "chain"     :  skill *= 0;		break;
			case "whip"      : 	skill *= 7;		break;
			default          :	skill *= 0;
		}
	// unarm stun.
	else skill *= 10;
	
	skill /= 10;
	skill += (int)me->query_stat("str")*2+(int)me->query_stat("int");
	skill -= (int)victim->query_stat("dex")*2 +(int)victim->query_stat("int");
	if (intp(victim->query("stun_difficulty")) )
	      if( random(skill) < (58 + (int)victim->query("stun_difficulty")) ) {
		tell_object(me,set_color("\n *** 哇!!! 沒點到! 看來你學藝不精哦! *** \n", "HIG",me) );
		return 1;
		}
	
	block_victim(me, victim);
	return  1;
}

int block_victim( object me, object victim )
{
	int my_str, vic_kar, times;

	tell_object( me, set_color( 
		"\n *** 你飛快的向對方一點，點到了"+victim->query("c_name")+
		"的"+stun_point[random(5)]+"穴，它無法攻擊了!!! ***\n", "HIY",me) );
		
	tell_object(victim, set_color( 
		me->query("c_name")+"電光火石的一點，點到你的穴道筋脈。\n", "HIM",victim));

	tell_room( environment(me), 
		me->query("c_name")+"突然伸出手指飛快地往"+
		victim->query("c_name")+"的身上一點。\n\n" ,
		({ me, victim }) );

	my_str = me->query_stat("str");
	vic_kar = victim->query_stat("karma");
        times= ( my_str - vic_kar ) / 4;
        if( times <= 1 ) times = 1  + random( (int)me->query("force_effect") + 1) / 2;

	me->add("force_points", -5 );
	victim->block_attack(times*2);
	victim->set_temp("msg_stop_attack", 
		set_color("( 你覺得被點中的部位痠麻難當，一點力氣也使不出來。 )\n", "HIM", victim) );
	return 1;
}
