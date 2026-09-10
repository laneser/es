// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/beholder";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Beholder.
	beholder::setup_race_body();
	add_action("do_gaze","gaze");
}

int do_gaze()
{
        object victim ;
        if ( !victim = query_attacker())
                return notify_fail("幹嘛？你又不在戰鬥中，用 look 就好了。\n");

        if ( query_temp("gazing") )
                return notify_fail("你正專心凝視你的敵人 ... \n");

        if ( victim->query("stop_attack") ) 
                return notify_fail("哈 ! 別白費力氣了，他已經睡著了。\n");

	tell_object(this_object(),"你用你的魔眼專心凝視著敵人 ...\n");

	tell_object(victim,sprintf("%s用他那妖異的魔眼凝視著你，你突然感到強烈的睡意。\n",query("c_name")));

        tell_room(environment(this_object()),
                  sprintf("%s用他妖異的眼睛凝視著%s。\n",query("c_name"),
                          victim->query("c_name")),({ this_object(),victim }));

        set_temp("gazing",1);
        call_out("sleeping",4,this_object(),victim);
        return 1;
}


void sleeping(object me,object victim)
{
	me->set_temp("gazing",0);
	if ( !me || !victim ) return;
        if ( !me->query_attacker() ) return ;
        if ( random((int)victim->query_level()*4) > (int)me->query_level() ) {
                tell_object(me,set_color("但是敵人不上當 ...\n","HIC",me));
                tell_object(victim,"你拼命的打起精神，說不睡就是不睡。\n");
                return;
	}
        victim->block_attack(4);
	victim->set_temp("msg_stop_attack",
                "( 你現在睡得正舒服！ )\n" );
        tell_object(me,set_color("敵人開始打鼾了 ...\n","HIY",me));
        return ;
}
