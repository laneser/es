#include <mudlib.h>
inherit DAEMON;

int help();
make_hurt(object me, object target, object weapon);
int result(object me,object target,object weapon,int succeed);
/* return value : 
   0 : 失敗
   1 : 一般
   2 以上 : special 
 */
int check_throw(object me,object target)
{
	int level,lv,kar,rate,skill,dex,rtn;

	skill = (int)me->query_skill("throw-dagger");
	if ( skill <= 0 ) 
		return 0;
	kar=(int)me->query_stat("kar")-(int)target->query_stat("kar");
	dex=(int)me->query_stat("dex")-(int)target->query_stat("dex");
	lv = (int)me->query("thief_level/throw-dagger");
	level = skill/5 - (int) target->query_level();
	rate = skill+lv*7+level*5+(kar+dex+dex)*2; 
	if ( rate > 600 ) rate = 600;
	if ( wizardp(me) )
		tell_object(me,"rate : " + rate + "/ 605 \n");
   	if ( rate > random(605) ) {
	    switch( random( (int)me->query("thief_level/throw-dagger")*10 ) ) {
		case 0..360 :
			rtn = 1;
			break;
		case 361..430 :
			rtn = 2;
			break;
		//	return 2;
		case 431..480 :
			rtn = 3;
			break;
		//	return 3;
		case 481..495 :
			rtn = 4;
			break;
		//	return 4;
		case 496..500 :
			rtn = 5;
			break;
		//	return 5;
	    } /* end of switch */
   	 } else {
		rtn = 0;
//   		return 0;
	}
	if ( wizardp(me) )
		tell_object(me,"rtn : " + rtn + "\n");
	return rtn;
}

calc_exp(object me,int dam)
{
	if ( dam )
		me->add("thief_exp/throw-dagger",dam/2);
	else {
		int i ;
		i = (int) me->query_skill("throw-dagger")/5 + 
		    (int) me->query("thief_level/throw-dagger");
		me->add("thief_exp/throw-dagger",random(i));
	}
}

int cmd_throw(string arg)
{
	string tmp1,tmp2;
	object me,target,weapon,env;

	me = this_player();
	if ( (int)me->query_temp("throwing") == 1 )
		return notify_fail("你手上的飛刀還沒射出去，急什麼。\n");
	if ( ! arg ) return notify_fail("你要投擲什麼?\n");
	if ( sscanf( arg,"%s at %s",tmp1,tmp2) != 2 ) return 0;
	if ( ! target = present(tmp2,(env=environment(me))))
		return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
	if ( ! living(target) )
		return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
	if ( ! (weapon = present(tmp1,me)) )
		return notify_fail("你沒有帶著叫"+tmp1+"的東東。\n");
	if ( target == me )
		return notify_fail("你不會拼suicide嗎?\n");
	if ( target->query("no_attack") )
		return notify_fail("你不能攻擊他。\n");
// 不能射 invisible 的 player
	if(!visible(target,me)||target->query("invisible_player") ) 
		return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
	if ( weapon && ( (string )weapon->query("type") != "dagger" || weapon->query("prevent_drop") || weapon->query("wielded") || weapon->query("equipped")))
		return notify_fail("這件東西不能當飛刀..\n");

	me->set_temp("throwing",1);
	tell_object( me,sprintf("你暗中拿了一%s%s, 等待適當的機會..\n",weapon->query("unit"),weapon->query("c_name")) );
	call_out("result",1,me,target,weapon,check_throw(this_player(),target) );

	return 1;
}

int result(object me,object target,object weapon,int succeed)
{
	object env;
	int dam=0;
	string message;
	me->set_temp("throwing",0);
	env = environment(me);
	if ( ! target || nullp(target) || target->query("hit_points") < 1 ) {
		write("那傢伙已經死了。\n");
		return 1;
	}
	if ( !present(target,env) ) {
		write(sprintf("%s已經溜走了!!\n",target->query("c_name")));
		return 1;
	}
/*
	switch (succeed){
	    case 1 :
	    case 2 :
	    case 3 :
	    case 4 :
	    case 5 :
	    default :
		message = "%s摸出一"+weapon->query("unit")+weapon->query("c_name")+", 咻的一聲射向%s, 結果%s!!\n";
		tell_room(env,set_color(
		  sprintf(message,me->query("c_name"),target->query("c_name"),"沒中"),"HIY",me),({me,target}));
		tell_object(target,set_color(
		  sprintf(message,me->query("c_name"),"你","被你閃過了"),"HIR",target));

		tell_object(me,
		sprintf(message,"你",target->query("c_name"),"沒中"));
		weapon->move(env);
	}
*/

	if ( succeed ) {
		tell_room( environment(me),
		set_color(sprintf("\n%s摸出一%s%s, 咻的一聲射中了%s!!\n",
		me->query("c_name"),weapon->query("unit"),weapon->query("c_name"),target->query("c_name")),"HIY"),
		({me,target}),
		);
		tell_object(target,sprintf("%s 射出暗器, 你覺得不妙!! \n",me->query("c_name")) );
		tell_object(me,sprintf("%s一個不留意, 中了你的暗器!\n",target->query("c_name")));
		dam=make_hurt(this_player(),target,weapon);
		weapon->move(target);
	} else {
		tell_room(env,
		set_color(sprintf("%s摸出一%s%s, 咻的一聲射向%s, 結果沒中.\n",
		me->query("c_name"),weapon->query("unit"),weapon->query("c_name"),target->query("c_name")),"HIY"),
		({me,target})
		);
		tell_object(target,sprintf("%s射出一把飛刀, 結果被你閃過了。\n",me->query("c_name")));
		tell_object(me,
		sprintf("你射出一把飛刀, 結果被%s閃過了! %s掉在地上...\n",target->query("c_name"),weapon->query("c_name")) );
		weapon->move(env);
	}


	if ( ! target->query_attackers() || member_array(me,target->query_attackers()) == -1 ) {
		tell_object(me,
		sprintf("%s喊道 : %s你這個小人, 要我的命就來拿吧 !\n",target->query("c_name"),me->query("c_name")));
	}
	target->kill_ob(me);
	calc_exp(me,dam);
}

make_hurt(object me, object target, object weapon)
{
	int dam,max,min,wc,ac;
	string msg;
	int exp;
	target->set("last_attacker",me);
	wc = weapon->query("weapon_class");
    	if ( wc ) {
		max = (int)weapon->query("max_damage");
		min = (int)weapon->query("min_damage");
		ac = (int)target->query("armor_class");
		dam = min + random(max - min);
		dam = dam - ac/6; 
		if ( dam <=0 ) 
			dam = random(min)+1;
		target->receive_damage(dam);
		me->gain_experience( dam+dam );
		if ( wizardp(me)) 
			tell_object(me,"dam = "+dam+ " exp = "+exp+"\n");	
     		msg = "/adm/daemons/statsd"->status_string(target) ;
		tell_object(target,sprintf("( 你%s )\n",msg));
		tell_object(me,sprintf("( %s%s )\n",target->query("c_name"),msg));
    	} else { /* 毒刀 */
	}
	return dam;
}

int help()
{
	write (@HELP
Usage: throw <weapon> at <target>

射飛刀就是射出一把小刀，趁著敵人不小心的時候讓他中標受傷，
這種飛刀的好處有兩個，一來容易取得，二來如果成功還可以回收，
當然是從敵人的屍體上拔回來。飛刀的種類當然是匕首類等輕巧的
武器。
HELP
);
	return 1;
}

