////#pragma save_binary

#include <mudlib.h>
inherit DAEMON;
int sneak_idle(object me,int succeed,string dir,string exit)
{
	string func;
	if ( (func = (string)environment(me)->query("pre_exit_func/"+dir)) && 
		call_other(environment(me),func) ) {
		return 1;
	}
	if ( succeed ) {
		me->set_temp("hidding",1);
		me->move_player(exit,"SNEAK");
		me->set_temp("block_command",1);
		me->set_temp("hidding",0);
		call_out("sneak_done",2,me);
		}
	else {
		me->move_player(exit,"",dir);
        	this_player()->block_attack(4);
        	this_player()->set_temp("msg_stop_attack",
        	"( 你潛行失敗，被敵人突襲，一陣手忙腳亂！ )\n" );
   	}	
	return 1;
}

int sneak_done(object me)
{
	me->delete_temp("block_command");
	return 1;
}
int check_sneak(object me)
{
	int skill;
	skill = (int)me->query_skill("sneak") ;
	if ( ! skill ) return 0;
	skill += (10 + (int)me->query("thief_level/backstab")/2);
   	if (random(140) < skill)
   		return 1;
   	else
   		return 0;
}
int cmd_sneak(string arg)
{
	string exit;
	mapping door;
	int delay;
	object env;

	env = environment(this_player()) ;

	if ( (int)this_player()->query_temp("next_action") > time() )
		return notify_fail("你正在做其他事情 ...\n");

	if ( ! arg ) return notify_fail("你要往哪裡潛行？\n");
	if ( !exit = env->query("exits/"+arg) )
		return notify_fail("那裡沒有任何出路。\n");
	if ( door = env->query("doors/"+arg) )
		if ( (string)env->query("doors/"+arg+"/status") != "open" )
			return notify_fail("那裡的門關著，你想穿過去嗎？\n");

	write(set_color(sprintf("你開始向%s潛行 ...\n",
			to_chinese(arg)),"HIY"));
	tell_room(env,
		sprintf("%s開始向%s潛行 ...\n",this_player()->query("c_name"),
			to_chinese(arg)),this_player());
	delay = 2 + random(4);
	this_player()->set_temp("hidding",0);
	this_player()->set_temp("next_action",time()+delay);
	call_out("sneak_idle",delay,this_player(),check_sneak(this_player()),
			arg,exit );	
	return 1;
}

int help()
{
	write (@HELP
Usage: sneak <dir>

這個指令能使你利用各種地形，隱秘的向期望的方向移動，這樣你可以
在別人毫不知覺的情況下移動到他所在的位置，雖然這有點難，但是隻
要成功了，他就根本不能查覺你的存在。

HELP
);
	return 1;
}
