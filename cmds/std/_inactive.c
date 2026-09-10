//#pragma save_binary
 
//	File	:  /cmds/std/_inactive.c
//	Created :  Watcher@TMI  (09/27/92)
//
//	Command to toggle user inactive mode.
 
#include <mudlib.h>

inherit DAEMON;

int cmd_inactive()
{
	object me;

	me = this_player();
	write("你決定暫停活動. 請按 [ENTER] 以繼續活動.\n");
	tell_room(environment(me), 
		sprintf("%s(%s)決定暫時停止活動。\n", me->query("c_name"),
			me->query("name")) , me);

	me->set("inactive", time());
 
	input_to("stop_inactive", 1);

	return 1;
}

int stop_inactive()
{
	object me;

	me = this_player();
	printf("你在停止活動 %s 後又開始活動.\n",
		format_time(time()-(int)me->query("inactive"), 1));
	tell_room(environment(me), 
		sprintf("%s(%s)又開始重新活動了。\n", me->query("c_name"),
			me->query("name")) , me);
	me->delete("inactive");
	return 1;
}
 
int help()
{
	write(@HELP

這個指令使你處於停止不動狀態.

HELP
);
	return 1;
}

// Prevent cleanup.
int clean_up()
{
	return 1;
}
