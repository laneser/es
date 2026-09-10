#include "mudlib.h"
#define         RATE ({ 13,20,32,55,68,70,75,80,87,90,95 })

inherit CONTAINER;

void create()
{
	::create();
	set_name("bag", "麻布袋");
	set_short("麻布袋");
	set_c_open_long("這個麻布袋是小偷常用來裝贓物的袋子，又寬又大的，\n好像很適合拿來蓋布袋(wrap)兼阿魯巴。\n");
	set( "weight", 20);
	set( "weight_apply", 50 );
	set( "max_load", 300);
	set( "value", ({ 220, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}

void init()
{
	add_action("do_wrap","wrap");
}
int do_wrap(string arg)
{
	object target, *members, *actor, me, leader_ob;
	string leader;
	int skill,rate,level,i;

	me = this_player();
	if ( sizeof(all_inventory()) ) return notify_fail("你把袋子扛了起來。\n");
	if ( !arg || arg == "" ) 
		return notify_fail("你把袋子捲起來。\n");

	if ( !me->query_vision() )
	        return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	if ( !target = present(arg,environment(me)) )
		return notify_fail("這裡沒有叫做 "+arg+" 的東東。\n");
	if ( !living(target) )
		return notify_fail("這裡沒有叫做 "+arg+" 的生物。\n");	
	if ( target->query_attacker() ) 
		return notify_fail("對方正在和人打架，你找不到機會出手。\n");
	if ( target->query("no_attack") )
		return notify_fail("你不可以欺負這種稀有動物，會遭天罰 ...\n");
	if ( target->query("user") ) {
		if ( (int)me->query_level() < 5 || 
			(int)target->query_level() < 5 ) 
			return notify_fail("還沒到欺負他的時候嘛 ... 等你(或他)長大吧 !!\n");
	}
	if ( !leader = me->query_temp("leader") ) 
		return notify_fail("要圍爐也得先找好幫手嘛 !! 先 Party 吧 !!\n");
	if ( !leader_ob = find_player(leader) )
		return notify_fail("你的隊長溜了 !! 重新 Party 吧 !!\n");
	members = leader_ob->query_temp("party_members") ;
	actor = ({ });
	for ( i = sizeof(members)-1 ; i >= 0 ; i--) {
		if ( environment(members[i]) == environment(me) )
			actor += ({ members[i] });
	}
	if ( sizeof(actor) < 2 ) 
		return notify_fail("只有你一個人在場啦 ... 怎麼圍爐？？\n");
	
	actor -= ({ me });
	
	tell_object(me,
		set_color("你拉出一個布袋，往"+target->query("c_name")+"罩下去 ...\n","HIY") );
	tell_object(target,
		set_color(me->query("c_name")+"突然拉出一個布袋，望你的頭上罩過來 ..\n","HIY"));
	tell_room(environment(me),set_color(me->query("c_name")+"突然拉出一個麻布袋，向"+target->query("c_name")+"的頭上罩下去 ...\n","HIY"),
		({ me,target }) );
	rate = (int)me->query_skill("trick") + (int)me->query_skill("hide") 
		+ (int)me->query_skill("sneak");
	rate += ((int)me->query_stat("dex") + (int)me->query_stat("kar") -
		 (int)target->query_stat("dex") - (int)target->query_stat("kar"))*10;
	level = (rate * (int)me->query_skill("trick"))/7000 ;
	if ( level < 0 ) 
		level = 0;
	else
		if ( level > 10 ) level = 10;
	target->kill_ob(me);
	if ( wizardp(me) )
		tell_object(me,sprintf("rate = %d , RATE = %d \n",rate,RATE[level]));
	if ( random(100) < RATE[level] ) {
		skill = (int)me->query_skill("trick")/10
			+ ((int)me->query_stat("kar")
			+ (int)me->query_stat("str")
			- (int)target->query_stat("str")
			- (int)target->query_stat("kar"))*2;
		if ( skill < 0 ) skill = 0;
		if ( skill > 60 ) skill = 60;
		
		tell_room(environment(me),
			sprintf("%s被罩個正著，只聽見%s大喊 : 圍～爐～嘍～ ....\n",target->query("c_name"),me->query("c_name"))
			, ({ target, me }));
		tell_object(me,target->query("c_name")+"還愣愣的在發呆 ... 呵呵呵 ～～～ 中獎啦 ...\n");
		tell_object(target,"你來不及躲開 ... 眼前登時一片漆黑 ～～　哇 !! 可惡的傢伙 !!\n");
		if ( wizardp(me) ) tell_object(me,"block "+(4+(skill/15)*2)+"\n");
		target->block_attack(4+(skill/15)*2);
		target->set_temp("msg_stop_attack",
			set_color("(你被人用布袋罩住，正在拼命的掙扎 !! )\n","HIY",target));
		me->block_attack(4+(skill/15)*2);
		me->set_temp("msg_stop_attack",
			set_color("(你正使勁地用布袋罩住"+target->query("c_name")+"，呦呵呵 ～～～ 好像騎野馬 !! )\n","HIC",me));


		this_object()->remove();
		return 1;
	}
	tell_room(environment(me),
		"但是"+target->query("c_name")+"突然向旁邊一閃，他撲了個空 ...\n", ({ me,target }) );
	tell_object(me,target->query("c_name")+"突然向旁邊一閃，不妙 ... 啊 ～～ 糗大了...\n");
	tell_object(target,"你急忙向旁邊一閃，讓他撲了個空，可惡的傢伙 !! 扁他 !!\n");
	return 1;	
}
