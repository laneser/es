//#pragma save_binary
#include <mudlib.h>
//	#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })
// 	#define RATE ({ 7,25,40,52,61,67,70,73,79,88,95 })
//	#define RATE ({ 3,16,27,39,50,60,67,75,82,90,95 })
#define 	RATE ({ 3,15,27,41,53,65,70,75,82,90,95 })
inherit DAEMON;

void remove_block(object me)
{
	me->delete_temp("block_command");
	return;
}

void make_hurt(object me,object target,object weapon)
{
	int dam,time,dam_align,victim_db ;
	string msg;
	target->set("last_attacker",me);
	time = target->query_temp("bs");
	victim_db = target->query("defense_bonus");
	dam = (int)me->query("max_damage1")+(int)me->query("min_damage1");
	dam = dam * (int)me->query_skill("dagger")/100 ;
	dam = dam + random( dam ) ;
	//dam = ( dam * 6 ) /( 4 + time ) ;
	dam = ( dam * 8 ) /( 5 + time ) ;
	dam_align = -(int)me->query("alignment")/2000 ;

	dam = (dam < 5 ? 5 : dam ) + random( (int)me->query_level() ) + 
			( dam_align > 20 ? 20 : dam_align )-victim_db;

//	write( sprintf("[ info ] damage : %d\n",dam) );
	target->receive_damage(dam);
	me->gain_experience(dam+dam);
	target->add_temp("bs",1);
	msg = "/adm/daemons/statsd"->status_string(target) ;
    tell_object( target,sprintf("( 你%s )\n",msg));
    printf("( %s%s )\n",target->query("c_name"),msg);
	return;
}

int backstab_idle(object me,object target,int succeed)
{
	object weapon;

	me->set_temp("backstabed",0);

	if ( !target || nullp(target) || target->query("hit_points") < 1) {
		write("那傢伙已經死了, 就放過他的□體吧 。\n");
		return 1; 
	}
	if ( !present(target,environment(me))) {
		write("哎呀 !! 目標溜走了 ..\n");
		return 1;
	}
	weapon = me->query("weapon1");
	tell_object(me,set_color(
		sprintf("好機會 !! 你握緊%s向%s的背用力刺下 !!\n",
			weapon->query("c_name"),target->query("c_name")),"HIY"));
			
	tell_room(environment(me),set_color(
		sprintf("%s的身影突然從%s背後浮現出來，眼中殺機重重 ...\n",
				me->query("c_name"),target->query("c_name")),"HIR"),
			({me,target}));


	if ( ! weapon ) succeed = 0;
	else if ( (string)weapon->query("type") != "dagger" )
		succeed = 0;

	me->kill_ob(target);
	target->kill_ob(me);
	if ( !succeed ) {
	tell_room(environment(me),
		sprintf("%s舉起他的%s朝著%s的背猛然刺落，哎呀 !! 竟然失手了 ...\n",
		me->query("c_name"),weapon->query("c_name"),target->query("c_name")),
		({ me,target}) );
		tell_object(me,set_color(
			sprintf("%s突然轉過頭來，對你詭異一笑，哎呀 !! 不妙 ...\n",
				target->query("c_name")),"HIR"));
		tell_object(target,set_color(
		sprintf("你突然感到情況不對，趕快向旁一閃，一道青白的弧光堪堪劃過\n"
					"你的背，你感到一陣毛骨悚然，可惡 !! 是%s的背刺 ...\n",
				me->query("c_name")),"HIM"));
        me->block_attack(4);
        me->set_temp("block_command",1);
        me->set_temp("msg_stop_attack",
                "( 你剛剛背刺失手，手忙腳亂，沒辦法做其他事 ! )\n" );
		call_out("remove_block",3,me);
		return 1;
	}	
	else {
	tell_room(environment(me),
		sprintf("%s舉起他的%s朝著%s的背猛然刺落，霎時血花四濺 ...\n",
		me->query("c_name"),weapon->query("c_name"),target->query("c_name")),
		({ me,target}) );
		tell_object(me,set_color(
			sprintf("%s一聲嘶吼，他的鮮血隨著你的%s噴了出來。成功了 !!\n"
					"一陣邪惡的快意自你心中升起 !! \n",
				target->query("c_name"),weapon->query("c_name")),"HIY"));
		tell_object(target,set_color(
		sprintf("你突然感到一陣劇痛，一截雪白的刀刃從你的胸口冒了出來，\n"
				"你不知所措的看著它，腦中一陣暈眩，可惡 !! 是%s的背刺 ...\n",
				me->query("c_name")),"HIR"));
		make_hurt(me,target,weapon);
		return 1;
	}
	return 1;
}

int check_backstab(object me,object target)
{
	int iq,dex,kar,rate,level,skill,lv;

	lv = target->query_level();
//	write("[ info ] hide_score : " + me->query_temp("hide_score") + "\n");
	if ( !me->query_temp("hidding") ||
		(int)me->query_temp("hide_score") < lv*lv) 
		return 0;
	skill = (int) me->query_skill("backstab");
	if ( ! skill ) return 0;
//	level = skill/5 - (int)target->query_level() + 6;
	level = skill/5 - (int)target->query_level() + 4;

	iq = (int)me->query_stat("int")-(int)target->query_stat("int");
	dex = (int)me->query_stat("dex")-(int)target->query_stat("dex");
	kar = (int)me->query_stat("kar")-(int)target->query_stat("kar");
	level = ( level < 0 ? 0 : level );
	level = ( level > 10 ? 10 : level );
	rate = RATE[level] + kar +kar + dex + dex + iq +iq;

//	write( sprintf("[ info ] rate = %d/120\n",rate) );
	if ( random(120) < rate )
		return 1;
	else
		return 0;
}
int cmd_backstab(string arg)
{
	object target,weapon;
	
	if ( this_player()->query_temp("backstabed") )
		return notify_fail("( 你現在正在專心等待背刺的時機！ )\n");
	if ( this_player()->query_temp("sneaked") )
		return notify_fail("( 你正在專心潛行, 無法背刺。)\n");
	if ( ! arg ) return notify_fail("你想背刺誰？\n");
	if ( !target = present( arg,environment(this_player())))
		return notify_fail("這裡沒有叫"+arg+"的生物。\n");
	if ( arg == (string)this_player()->query("name"))
		return notify_fail("背刺自己？你不會拼 suicide 嗎？\n");
	if ( ! living(target) ) 
		return notify_fail("你用力的戳了"
			+target->query("c_name")+"但是什麼事也沒發生。\n");
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("你想背刺誰？\n");
	if ( !this_player()->query_vision() )
		return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	if ( target->query("no_attack") )
		return notify_fail("這傢伙－不能殺。\n");
	if ( userp(target) ) {
		if ( (int)target->query_level()< 5 || 
			 (int)this_player()->query_level()<5 )
		return notify_fail("你不能 PK 他 !!\n");
	}
	weapon = this_player()->query("weapon1");
	if ( !weapon )
		return notify_fail("你沒有武器，無法背刺 !!\n");	
	if ( (string)weapon->query("type") != "dagger" )
		return notify_fail("你的武器不趁手，無法背刺 !!\n");
	if ( (int)this_player()->query("alignment")>0 )
		return notify_fail("一陣天人交戰，你實在下不了手來幹這種可怕的事。\n");
			
	write(set_color(sprintf("你開始等待背刺%s的時機 ...\n",target->query("c_name")),"HIY"));

        this_player()->block_attack(4);
        this_player()->set_temp("msg_stop_attack",
                "( 你現在正在專心等待背刺的時機，無法做其他事！ )\n" );
        this_player()->set_temp("backstabed",1);
	call_out("backstab_idle",2+random(4),this_player(),target,
				check_backstab(this_player(),target));
	return 1;
}

int help()
{
	write (@HELP
Usage: backstab <target>

當你的目標對你完全沒有戒心的一瞬間，你可以利用這個指令來"背刺"他，
這個可怕的突襲會造成極大的傷口，對於比較弱的敵人甚至可能一擊致命，
不過，如果你的敵人事先查覺你的企圖，你就得要當心他將計就計了。

HELP
);
	return 1;
}
