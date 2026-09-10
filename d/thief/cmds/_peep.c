//#pragma save_binary

#include <mudlib.h>
#define RATE ({ 5,20,32,41,47,50,53,59,68,80,95, })

inherit DAEMON;

int peep_idle(object me,int succeed,object target,object item)
{
	mapping wealth ;
	string *coins;
	int i,coin;
	
	me->set_temp("peeped",0);
	if ( nullp(target) )
		return notify_fail("你要偷窺的對象已經不在這裡了 !!\n");
	if ( target && !present(target,environment(me)) ) 
		return notify_fail("你要偷窺的對象已經不在這裡了 !!\n");
	if ( succeed ) {
		tell_object(me,set_color(
		sprintf("趁著%s不留意的時候，你盡情的打量%s ...\n",
			target->query("c_name"),
			( !item ? target->query("c_name") : item->query("c_name") ))
			,"HIY") );
		me->set_temp("peeping",1);
	} else
	{
	tell_object(me,set_color(
		sprintf("%s突然轉過頭狠狠地瞪了你一眼，好像發現了你的意圖 ...\n",
			target->query("c_name")),"HIM") );
	tell_object(target,set_color(
		sprintf("你突然感到背上涼颼颼的，好像有人在偷窺你 ...\n"),"HIY") );
	me->delete_temp("peeping");
	return 1;
	}
	if ( ! item ) {
		tell_object(me,"/cmds/std/_look"->living_description(me,target));
		me->delete_temp("peeping");
	// if succeed can look money .. :P)
		if ( succeed && wealth = target->query("wealth")) {
//			wealth = target->query("wealth");
			
			coins = keys(wealth);
			for ( i=0 ,coin = 0; i < sizeof(coins) ; i++ )
				coin += wealth[coins[i]] ;
			if ( coin ) 
				printf("\n%s的揹包裡還有 %d 枚錢幣。\n",target->query("c_name"),coin);	
			else
				printf("\n%s身無分文。\n",target->query("c_name"));
		}
		return 1;
	}
	if ( succeed )
		tell_object(me,item->query("long"));
	return 1;
}
int check_peep(object me,object target)
{
	int iq,kar,level,rate;

//	level = (int)this_player()->query_level();
	iq = (int)me->query_stat("int") - (int)target->query("int");
	kar = (int)me->query_stat("kar") - (int)target->query("kar");
	level = (int)me->query_skill("peep")/5 - (int)target->query_level() + 1;
	level = (level < 0 ? 0 : level);
	level = ( level > 10 ? 10 : level );
   	rate = RATE[level] + iq + kar + kar;
//	rate = rate * (int) me->query_skill("peep")/100;
   	rate = ( rate > 95 ? 95 : rate ) ;
   	if ( random(100) < rate )
   		return 1;
   	else
   		return 0;
}
int cmd_peep(string arg)
{
	string tmp1,tmp2;
	object target,item;

	if ( this_player()->query_temp("peeped") )
		return notify_fail("你正在努力偷窺中 ...\n");
	if ( ! arg )
		return notify_fail("你要偷窺什麼？\n");

	item = 0;
	if ( sscanf( arg,"%s of %s",tmp1,tmp2) == 2 ) {
		if ( ! target = present(tmp2,environment(this_player()) ) )
			return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
		if ( ! living(target) )
			return notify_fail("這裡沒有叫"+tmp2+"的生物。\n");
		if ( ! item = present(tmp1,target ) )
			return notify_fail(target->query("c_name")+"沒有帶著叫"+tmp1+"的東東。\n");
	}
	else {
	if ( ! target = present(arg,environment(this_player()) ))
		return notify_fail("這裡沒有叫"+arg+"的東東。\n");
	if ( ! living(target) )
		return notify_fail("這裡沒有叫"+arg+"的生物。\n");
	}
//	if ( target == this_player() )
//		return notify_fail("你真無聊耶, peep 自己, 變態啊?\n");

	write(set_color(sprintf("你開始用眼角的餘光偷偷打量%s的一舉一動。\n",
			target->query("c_name")),"HIY"));
	this_player()->set_temp("peeped",1);
	call_out("peep_idle",3,this_player(),check_peep(this_player(),target)
				,target,item );
	return 1;
}

int help()
{
	write (@HELP
Usage: peep <target>
       peep <object> of <target>

這個指令能使你在別人毫不知覺的情況下偷窺他的狀況、攜帶的物品、金錢
甚至他揹包裡袋子的內容。在下手"借"別人的東西之前，最好養成先觀察觀
察的好習慣，隨手亂摸是很容易被發現的。

HELP
);
	return 1;
}
