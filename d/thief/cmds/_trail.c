#include <mudlib.h>
#define TRACE_OB "/obj/trace_object"
inherit DAEMON;

int help();

int find_trace_ob(object env)
{
	object *ob;
	int i;
	ob = all_inventory(env);
	for ( i = sizeof(ob)-1; i >= 0; i-- ) 
		if ( (string) ob[i]->query("name") == "trace object" )
			return 1;
	return 0;
}

void stop_trace(object me)
{
	object target,*tmp;

	if ( ! (target = (object) me->query_temp("trace_target")) ) {
		tell_object(me,"你並沒有跟蹤任何人。\n");
		return ;
	}
	if ( !(tmp = target->query_temp("tracers")) ) {
		tell_object(me,"你並沒有跟蹤任何人。\n");
		return ;
	}
	tmp -= ({me});
	target->set_temp("tracers",tmp);
	me->delete_temp("trace_target");
	tell_object(me,"你停止跟蹤"+target->query("c_name")+"。\n");
//	me->set_temp("trace_skill",0);
}

int cmd_trail(string arg)
{
	object target,me,trace_ob,o_target;

	me = this_player();
	if (  !wizardp(me) )  return 0;
	if ( (int) me->query_temp("next_action") > time() )
		return notify_fail("你正在專心做別的事!!\n");
	if ( ! arg ) {
		target = me->query_temp("trace_target");
		if ( target )
			write("你正在跟蹤" + target->query("c_name")+"。\n"); 
		else
			write("你現在沒有跟蹤任何人。\n");
		return 1;
	}
	if ( arg == "none" ) {
		stop_trace(me);
		return 1;
	}
	if ( !(target=present(arg,environment(me))) )
		return notify_fail("這裡沒有叫 " + arg + " 的生物。\n");
	if ( !visible(target,me))
		return notify_fail("這裡沒有叫 " + arg + " 的生物。\n");

	if ( ! living(target) ) 
		return notify_fail("你只能跟蹤生物。\n");

	if ( target == me ) {
		stop_trace(me);
		return 1;
	}	
	o_target = me->query_temp("trace_target");
	if ( o_target ) {
	    if ( o_target != target ) 
		return notify_fail("你正在跟蹤另一個人,你必須先停止跟蹤他。\n");
	    else 
		return notify_fail("你已經在跟蹤他了。\n");
	} 
	target->add_temp("tracers",({me}) );
	me->set_temp("trace_target",target);
	if ( find_trace_ob(target) != 1 ) {
		trace_ob = new(TRACE_OB);
		trace_ob->move(target);
	}
	me->quick_message(sprintf("你開始跟蹤%s...\n",target->query("c_name")));
	return 1;
}

help()
{
	write(@C_HELP
Usage : trail [ 某人 | none ]
	這個指令可以使你在隱藏自己的行蹤之後, 悄悄的跟著某人走而不被發現，
	當然了, 跟蹤的成敗跟技巧的相關性是很大的, 多少也跟運氣相關。萬一被
	發現了, 可能會被揍一頓喔 ..
	另外, 你只能跟蹤玩家。
	trail none : 停止跟蹤。
C_HELP);
}
