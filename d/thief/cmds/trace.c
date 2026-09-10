#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_trace(string arg)
{
	object target,me;

	me = this_player();
	if ( (int) me->query_temp("next_action") > time() )
		return notify_fail("你正在專心做別的事!!");
	if ( ! arg ) {
		target = me->query_temp("trace_target");
		if ( nullp(target) )
			write("你現在沒有跟蹤任何人.");
		else
			write("你正在跟蹤" + target->query("c_name")+"."); 
		return 1;
	}
	if ( !(target=present(arg,environment(me))) )
		return notify_fail("這裡沒有叫 " + arg + " 的生物");
	if ( ! visible(target,me) )
		return notify_fail("這裡沒有叫 " + arg + " 的生物");
	if ( target == me ) {
		stop_trace(me);
		return 1;
	}	
	target->add_temp("tracer",({"me" }));
	
}

stop_trace(object me)
{
	me->delete_temp("trace_target");
//	target->_temp("tracer",({"me" }));
}

help()
{
	write(@C_HELP
Usage : trace <某人>
	跟蹤某人, 等到適當時機再突下殺手.
	trace <自己>
	停止跟蹤
	trace 
	正在跟蹤誰
C_HELP);
}
