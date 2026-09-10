// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/halfling";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Halfling.
	halfling::setup_race_body();
	modify_skill("trading",query_level()*2);
	add_action("do_joke","joke");
}

int do_joke()
{
	string laugh,*action = ({ "%s指著%s的鼻子笑得直不起腰來。\n", 
			"%s在%s的四周跳來跳去，拿大鼎、翻跟斗。\n", 
			"%s裝上一個紅紅的小丑鼻子，對著%s搖頭晃腦。\n", 
			"%s一屁股坐在地上，指著%s哇啦哇啦的哭了起來。\n",
			"%s用泥巴亂塗%s的臉。\n" }) ;
	object victim ;
	if ( !victim = query_attacker())
		return notify_fail("幹嘛？耍寶嗎？你又不在戰鬥中。\n");

        if ( query_temp("joking") )
                return notify_fail("你正在努力耍寶中 ... \n");
    if( query_temp("busy") )
    	return notify_fail("\n  你正在專心作別的事情，不能分心耍寶。\n");
	if ( victim->query("stop_attack") || 
		(int)victim->query_temp("be_joke")==3 )
		return notify_fail("哈 ! 別白費力氣了，他現在可不會上當了。\n");

        laugh = action[random(5)];

	tell_object(this_object(),"你對著敵人努力的耍寶 ...\n");

	tell_object(victim,sprintf(laugh,query("c_name"),"你"));

	tell_room(environment(this_object()),
		  sprintf(laugh,query("c_name"),
			  victim->query("c_name")),({ this_object(),victim }));

	set_temp("joking",1);
	set_temp("busy",1);
	call_out("funny",2,this_object(),victim);
	return 1;
}

void funny(object me,object victim)
{
	int i;
	me->set_temp("joking",0);
	me->delete_temp("busy");

	if ( !me->query_attacker() || !victim || nullp(victim) ) return ;
        i=7+victim->query_perm_stat("int")-me->query_perm_stat("int");
	i=i/10;
        if (i < 0) i = 0;
	if ( random(3) < (i+(int)victim->query_temp("be_joke")) ) {
		tell_object(me,set_color("但是敵人不為所動 ...\n","HIC",me));
		tell_object(victim,"你拼命的忍住笑，不能上當。\n");
		return;
	}
        victim->block_attack(4);
	victim->set_temp("msg_stop_attack",
		"( 你現在笑得渾身沒力，無法攻擊！ )\n" );
	victim->add_temp("be_joke",1);
	tell_object(me,set_color("敵人笑得直不起腰來，好機會 ...\n","HIY",me));
	return ;
}
