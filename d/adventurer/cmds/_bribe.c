//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int help();
int bribe_work(object me, object victim, int charm);
int cmd_bribe()
{
	int skill, tp_cost, delay, num, charm, num1, time;
	object me, victim;
	
	me = this_player();
    if( me->query_level() < 5 )
        return notify_fail("你到底想幹嘛啦?\n");
    if( me->query_temp("bribe_busy") )
    	return notify_fail("同時賄賂兩個人是不可能的。\n");

	victim = me->query_attacker();
	
switch( me->query("race") ) {
	case "human" : 	charm == 3;		break;
	case "elf"        :  charm == 4;		break;
	case "dwarf":  charm == 2;		break;
	case "orc"    : 	charm == 1;		break;
	case "gnome"     : 	charm == 3;		break;
	case "halfling"       : 	charm == 4;		break;
	case "lizardman" : 	charm == 1;		break;
	case "imp"   : 	charm == 3;		break;
	case "daemon"     :  charm == 4;		break;
	case "vampire"      : 	charm == 4;		break;
	case "beholder" :  charm == 5;             break;
	case "drow" :  charm == 3;             break;
	default          :	charm == 2;
		}
	

	if( !victim ) return notify_fail("你沒在戰鬥中，找不到對手在哪裡!\n");
	if( !skill = (int)me->query_skill("polemic") )
		return notify_fail( "你沒有學過辯術，口才也不好，怎麼去賄賂別人呢 !!!\n");
        if( victim->query("prevent_give_money") )
                return notify_fail("這傢伙看來是不能賄賂的!\n");
        num1 = (victim->query_level()+26)/me->query_level();
	
	time = victim->query_temp("bribe_time") ; 
	num = 5*(1 + time*time)*num1;
	tp_cost = 65 - (skill / 6) - (5 * charm);
	if( !tp_cost || (int)me->query("talk_points") < (tp_cost + 1) )
		return notify_fail("你講了太多話了，現在一句話都說不出來！\n");
	if (me->query("wealth/gold")<num+1)
	        return notify_fail("賄賂最好用金幣，但你的金幣不夠！\n");
	else
		me->add("talk_points", -tp_cost );

	tell_object(me, set_color("你鼓起如簧之舌，雙手捧起一把金幣，開始賄賂你的對手 ! \n", "HIC",me) );
	tell_object(victim, set_color("你看到"+me->query("c_name")+"帶著一臉諂媚的笑容走到你面前試圖賄賂你! \n", "HIC",victim) ); 
        tell_room( environment(me),
                me->query("c_name")+"滿臉陪笑的走到"+
                victim->query("c_name")+"的面前試圖賄賂他。\n" ,({ me, victim }) );
        delay = 6 - skill/10 - (charm+1)/2;  
        if( delay < 0 ) delay = 1;
        else delay = 2;
               
	
	me->set_temp("bribe_busy",1);
	call_out("bribe_work", delay, me, victim, charm);
	return 1;
}

int bribe_work(object me, object victim, int charm)
{
	int my_kar,vic_int,level,vic_level,chance,skill,num,num1,time;
        string gold;
	
	me->delete_temp("bribe_busy");
	skill = me->query_skill("polemic");
	my_kar = me->query_stat("karma");
	vic_int = victim->query_stat("int");
        time = victim->query_temp("bribe_time");
        level = me->query_level();
        vic_level = victim->query_level();
	chance = my_kar-vic_int+level-2*vic_level;
	num1 = (victim->query_level()+26)/me->query_level();
	num = 5*(1 + time*time)*num1;
	if (me->query("wealth/gold")<num+1) 
	                return notify_fail("你以為你很聰明嗎??別傻了！\n");
	if ( ! me->query_attackers() || !victim || victim->query("hit_points") < 1) {
		tell_object(me,"你的戰鬥結束了，不要浪費錢了! \n");
		return 1;
	}
	if( skill+chance+random(3*charm)+random(skill) < vic_int+vic_level ) {
		tell_object(me,set_color("你的敵人很高興的接過你手上的金幣，然後繼續打你!\n", "HIG",me) );
		tell_object(victim,set_color("你搖頭嘆道: 可憐的瘋子，臨死錢還送錢給我! \n", "HIC",victim) );
	        tell_room( environment(me),"\n"+
		victim->query("c_name")+"搖頭嘆道: 可憐的瘋子，臨死錢還送錢給我! \n\n" ,
	        ({ me, victim }) );
		me->add("wealth/gold",-num);
		victim->add("wealth/gold",num);
		return 1;
	}

        victim->remove_attacker(me);
        me->remove_attacker(victim);
//        me->cease_all_attacks();
        me->add("wealth/gold",-num);
	victim->add("wealth/gold",num);
	victim->add_temp("bribe_time",1);
	tell_object( me, set_color( 
		"你成功的說服敵人，用一些金幣換來短暫的和平....\n", "HIY",me) );
		
	tell_object(victim, set_color( 
		me->query("c_name")+"給你一大把金幣，你看的眼花撩亂，喪失了50%的戰鬥意志。\n", "HIM",victim));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"拿出一大把金幣塞到"+
		victim->query("c_name")+"的身上，使得他停止對"+me->query("c_name")+"的攻擊。\n\n" ,
		({ me, victim }) );
                return 1;
}
int help()
{
   write(
@C_HELP
指令格式: bribe 
   
這個指令讓你有能力在戰鬥時使用金幣去賄賂敵人，並使其放棄對
你的敵意。成功的機率與花費的金幣數目與使用者本身的辯術有關
同時也與敵人的智力有關，若施術成功則可免去一場不必要的戰爭
，若失敗則你將損失一筆錢。
如果該敵人先前曾接受你的賄賂，想再成功的賄賂則需要付出比上
更多的金錢。
C_HELP
   );
   return 1;
}   
